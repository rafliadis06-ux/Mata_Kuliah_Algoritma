#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
using namespace std;

struct Process {
    string name;
    int at, bt, ct, tat, wt, rt, q;
    int remaining;
    bool started = false;
};

int main() {
    int n;
    cout << "Masukkan jumlah proses: ";
    cin >> n;

    int quantumRR;
    cout << "Masukkan quantum untuk Queue 1 (RR): ";
    cin >> quantumRR;

    vector<Process> p(n);
    for (int i = 0; i < n; i++) {
        cout << "Proses " << i+1 << " (Nama AT BT Queue): ";
        cin >> p[i].name >> p[i].at >> p[i].bt >> p[i].q;
        p[i].remaining = p[i].bt;
    }

    int time = 0, completed = 0;
    queue<int> rrQ, fcfsQ;
    vector<string> gantt;

    while (completed < n) {
        // Tambah proses datang ke queue
        for (int i = 0; i < n; i++) {
            if (p[i].at == time) {
                if (p[i].q == 1) rrQ.push(i);
                else fcfsQ.push(i);
            }
        }

        if (!rrQ.empty()) {
            int idx = rrQ.front(); rrQ.pop();
            if (!p[idx].started) {
                p[idx].rt = time - p[idx].at;
                p[idx].started = true;
            }

            int quantum = min(quantumRR, p[idx].remaining);

            for (int q = 0; q < quantum; q++) {
                gantt.push_back(p[idx].name + "(Q1)");
                p[idx].remaining--;
                time++;

                // Cek proses datang
                for (int i = 0; i < n; i++) {
                    if (p[i].at == time) {
                        if (p[i].q == 1) rrQ.push(i);
                        else fcfsQ.push(i);
                    }
                }

                if (p[idx].remaining == 0) break;
            }

            if (p[idx].remaining > 0) rrQ.push(idx);
            else {
                p[idx].ct = time;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
                completed++;
            }

        } else if (!fcfsQ.empty()) {
            int idx = fcfsQ.front(); fcfsQ.pop();

            if (!p[idx].started) {
                p[idx].rt = time - p[idx].at;
                p[idx].started = true;
            }

            while (p[idx].remaining > 0) {
                gantt.push_back(p[idx].name + "(Q2)");
                p[idx].remaining--;
                time++;

                for (int i = 0; i < n; i++) {
                    if (p[i].at == time) {
                        if (p[i].q == 1) rrQ.push(i);
                        else fcfsQ.push(i);
                    }
                }

                if (!rrQ.empty()) break; // preempt jika Q1 datang
            }

            if (p[idx].remaining == 0) {
                p[idx].ct = time;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
                completed++;
            } else {
                fcfsQ.push(idx);
            }

        } else {
            gantt.push_back("-");
            time++;
        }
    }

    // Output Tabel
    cout << "\nTABEL HASIL:\n";
    cout << "+--------+-----+-----+-----+-----+-----+-----+-----+\n";
    cout << "| Proses | AT  | BT  | Q   | CT  | TAT | WT  | RT  |\n";
    cout << "+--------+-----+-----+-----+-----+-----+-----+-----+\n";
    for (auto &x : p) {
        cout << "| " << setw(6) << x.name 
             << " | " << setw(3) << x.at 
             << " | " << setw(3) << x.bt 
             << " | " << setw(3) << x.q 
             << " | " << setw(3) << x.ct 
             << " | " << setw(3) << x.tat 
             << " | " << setw(3) << x.wt 
             << " | " << setw(3) << x.rt << " |\n";
    }
    cout << "+--------+-----+-----+-----+-----+-----+-----+-----+\n";

    // Gantt Chart
    cout << "\nGANTT CHART:\n";
    for (auto &g : gantt) cout << "[" << g << "]";
    cout << "\n";

    // Rata-rata
    double sumWT1=0, sumTAT1=0, cnt1=0;
    double sumWT2=0, sumTAT2=0, cnt2=0;

    for (auto &x : p) {
        if (x.q == 1) {
            sumWT1 += x.wt; sumTAT1 += x.tat; cnt1++;
        } else {
            sumWT2 += x.wt; sumTAT2 += x.tat; cnt2++;
        }
    }

    cout << "\nQuantum Queue 1 (RR): " << quantumRR << endl;

    cout << "\nRata-rata WT & TAT:\n";
    if (cnt1>0) cout << "Queue 1 (RR): WT=" << sumWT1/cnt1 << ", TAT=" << sumTAT1/cnt1 << endl;
    if (cnt2>0) cout << "Queue 2 (FCFS): WT=" << sumWT2/cnt2 << ", TAT=" << sumTAT2/cnt2 << endl;

    // Analisis
    cout << "\nAnalisis MLQ:\n";
    cout << "- Kelebihan: Proses prioritas tinggi (Q1) dilayani cepat dengan Round Robin.\n";
    cout << "- Kelemahan: Proses di Q2 dapat mengalami starvation jika Q1 selalu penuh.\n";
}
