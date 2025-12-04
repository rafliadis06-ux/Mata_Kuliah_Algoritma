#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <thread>
#include <chrono>
using namespace std;

struct Process {
    string name;
    int at, bt, priority;
    int ct, tat, wt, rt;
    int remaining;
    bool started = false;
    int lastWait = 0; // untuk menghitung aging
};

int main() {
    int n;
    cout << "Masukkan jumlah proses: ";
    cin >> n;

    vector<Process> p(n);
    for (int i = 0; i < n; i++) {
        cout << "Proses " << i+1 << " (Nama AT BT Priority): ";
        cin >> p[i].name >> p[i].at >> p[i].bt >> p[i].priority;
        p[i].remaining = p[i].bt;
    }

    int time = 0, completed = 0, priorityChanges = 0;
    vector<string> gantt;

    while (completed < n) {
        // Aging rule: cek proses yang menunggu
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].remaining > 0) {
                int waiting = time - p[i].at - (p[i].bt - p[i].remaining);
                if (waiting > 5) {
                    p[i].priority--;
                    priorityChanges++;
                    // reset agar tidak terus berulang setiap tick
                    p[i].at = time; 
                }
            }
        }

        // Pilih proses dengan prioritas tertinggi (angka kecil = lebih tinggi)
        int idx = -1;
        int bestPriority = 1e9;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].remaining > 0) {
                if (p[i].priority < bestPriority) {
                    bestPriority = p[i].priority;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            if (!p[idx].started) {
                p[idx].rt = time - p[idx].at;
                p[idx].started = true;
            }

            gantt.push_back(p[idx].name + "(P" + to_string(p[idx].priority) + ")");
            p[idx].remaining--;
            time++;

            if (p[idx].remaining == 0) {
                p[idx].ct = time;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
                completed++;
            }
        } else {
            gantt.push_back("-");
            time++;
        }
    }

    // Output tabel hasil
    cout << "\nTABEL HASIL:\n";
    cout << "+--------+-----+-----+---------+-----+-----+-----+\n";
    cout << "| Proses | AT  | BT  | Priority | CT  | TAT | WT  | RT  |\n";
    cout << "+--------+-----+-----+---------+-----+-----+-----+\n";
    for (auto &x : p) {
        cout << "| " << setw(6) << x.name 
             << " | " << setw(3) << x.at 
             << " | " << setw(3) << x.bt 
             << " | " << setw(7) << x.priority 
             << " | " << setw(3) << x.ct 
             << " | " << setw(3) << x.tat 
             << " | " << setw(3) << x.wt 
             << " | " << setw(3) << x.rt << " |\n";
    }
    cout << "+--------+-----+-----+---------+-----+-----+-----+\n";

    // Gantt Chart
    cout << "\nGANTT CHART:\n";
    for (auto &g : gantt) cout << "[" << g << "]";
    cout << "\n";

    // Jumlah perubahan priority
    cout << "\nJumlah perubahan priority (aging): " << priorityChanges << endl;

    // Analisis starvation
    cout << "\nAnalisis Starvation:\n";
    cout << "- Tanpa aging, proses dengan priority rendah bisa menunggu sangat lama.\n";
    cout << "- Dengan aging, setiap proses yang menunggu >5 satuan waktu akan naik prioritas.\n";
    cout << "- Hal ini mencegah starvation karena proses lambat tetap mendapat giliran.\n";
}