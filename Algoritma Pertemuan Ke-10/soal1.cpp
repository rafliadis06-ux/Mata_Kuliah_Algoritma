#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Process {
    string name;
    int at, bt, ct, tat, wt, rt;
    int remaining;
    bool started = false;
};

int main() {
    int n;
    cout << "Masukkan jumlah proses: ";
    cin >> n;

    vector<Process> p(n);
    for (int i = 0; i < n; i++) {
        cout << "Proses " << i+1 << " (Nama AT BT): ";
        cin >> p[i].name >> p[i].at >> p[i].bt;
        p[i].remaining = p[i].bt;
    }

    int time = 0, completed = 0, preemptions = 0;
    vector<string> gantt;

    while (completed < n) {
        int idx = -1;
        int minRemaining = 1e9;

        // Cari proses dengan remaining time terkecil
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].remaining > 0) {
                if (p[i].remaining < minRemaining) {
                    minRemaining = p[i].remaining;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            if (!p[idx].started) {
                p[idx].rt = time - p[idx].at;
                p[idx].started = true;
            }

            gantt.push_back(p[idx].name);
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

        // Hitung preemption
        if (gantt.size() > 1 && gantt[gantt.size()-1] != gantt[gantt.size()-2])
            preemptions++;
    }

    // ====================== OUTPUT TABEL RAPI ======================
    cout << "\nTABEL HASIL:\n";
    cout << "+--------+-----+-----+-----+-----+-----+-----+\n";
    cout << "| Proses | AT  | BT  | CT  | TAT | WT  | RT  |\n";
    cout << "+--------+-----+-----+-----+-----+-----+-----+\n";

    for (auto &x : p) {
        cout << "| "
             << setw(6) << x.name << " | "
             << setw(3) << x.at   << " | "
             << setw(3) << x.bt   << " | "
             << setw(3) << x.ct   << " | "
             << setw(3) << x.tat  << " | "
             << setw(3) << x.wt   << " | "
             << setw(3) << x.rt   << " |\n";
    }

    cout << "+--------+-----+-----+-----+-----+-----+-----+\n";

    // ====================== GANTT CHART ===========================
    cout << "\nGANTT CHART:\n";
    for (auto &g : gantt) cout << "[" << g << "]";
    cout << "\n";

    // ====================== INFORMASI PREEMPTION ===================
    cout << "\nJumlah Preemption: " << preemptions << endl;

    // ====================== ANALISIS STARVATION ====================
    cout << "\nAnalisis Starvation:\n";
    cout << "- SRTF bisa menyebabkan proses dengan burst time besar terus ditunda oleh proses kecil.\n";
    cout << "- Namun dalam simulasi ini, semua proses tetap selesai sehingga tidak terjadi starvation permanen.\n";
}
