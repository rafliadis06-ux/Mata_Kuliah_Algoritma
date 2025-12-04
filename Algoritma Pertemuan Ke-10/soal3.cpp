#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Process {
    string name;
    int at, bt, ct, tat, wt, rt, queue;
    int remaining;
    bool started = false;
};

int main() {
    int n;
    cout << "Masukkan jumlah proses: ";
    cin >> n;

    vector<Process> p(n);
    for (int i = 0; i < n; i++) {
        cout << "Proses " << i+1 << " (Nama AT BT Queue): ";
        cin >> p[i].name >> p[i].at >> p[i].bt >> p[i].queue;
        p[i].remaining = p[i].bt;
    }

    int time = 0, completed = 0;
    queue<int> rrQ, fcfsQ;
    vector<string> gantt;

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (p[i].at == time) {
                if (p[i].queue == 1) rrQ.push(i);
                else fcfsQ.push(i);
            }
        }

        if (!rrQ.empty()) {
            int idx = rrQ.front(); rrQ.pop();
            if (!p[idx].started) {
                p[idx].rt = time - p[idx].at;
                p[idx].started = true;
            }
            int quantum = min(2, p[idx].remaining);
            for (int q = 0; q < quantum; q++) {
                gantt.push_back(p[idx].name + "(Q1)");
                p[idx].remaining--;
                time++;
                for (int i = 0; i < n; i++) {
                    if (p[i].at == time) {
                        if (p[i].queue == 1) rrQ.push(i);
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
                        if (p[i].queue == 1) rrQ.push(i);
                        else fcfsQ.push(i);
                    }
                }
            }
            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            completed++;
        } else {
            gantt.push_back("-");