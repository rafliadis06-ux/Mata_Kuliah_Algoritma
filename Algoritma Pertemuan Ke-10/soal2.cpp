#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    string name;
    int at, bt, priority;
    int ct, tat, wt, rt;
    int remaining;
    bool started = false;
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
        // Aging rule
        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].remaining > 0) {
                int waiting = time - p[i].at - (p[i].bt - p[i].remaining);
                if (waiting > 5) {
                    p[i].priority--;
                    priorityChanges++;
                }
            }
        }

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
    }

    cout << "\nHasil:\n";
    cout << "Proses\tAT\tBT\tCT\tTAT\tWT\tRT\tPriority\n";
    for (auto &x : p) {
        cout << x.name << "\t" << x.at << "\t" << x.bt << "\t"
             << x.ct << "\t" << x.tat << "\t" << x.wt << "\t" << x.rt
             << "\t" << x.priority << "\n";
    }

    cout << "\nGantt Chart: ";
    for (auto &g : gantt) cout << g << " ";
    cout << "\nJumlah perubahan priority: " << priorityChanges << endl;
}