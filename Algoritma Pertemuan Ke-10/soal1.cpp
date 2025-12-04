#include <iostream>
#include <vector>
#include <algorithm>
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

        if (gantt.size() > 1 && gantt[gantt.size()-1] != gantt[gantt.size()-2])
            preemptions++;
    }

    cout << "\nHasil:\n";
    cout << "Proses\tAT\tBT\tCT\tTAT\tWT\tRT\n";
    for (auto &x : p) {
        cout << x.name << "\t" << x.at << "\t" << x.bt << "\t"
             << x.ct << "\t" << x.tat << "\t" << x.wt << "\t" << x.rt << "\n";
    }

    cout << "\nGantt Chart: ";
    for (auto &g : gantt) cout << g << " ";
    cout << "\nJumlah Preemption: " << preemptions << endl;
}