#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    string name;
    int burst;
    int remaining;
    int waiting;
    int turnaround;
};

int main() {
    int n, quantum;
    cout << "Masukkan jumlah proses: ";
    if (!(cin >> n)) return 0;
    cout << "Masukkan quantum time: ";
    cin >> quantum;

    vector<Process> p(n);
    queue<int> q;
    for (int i = 0; i < n; i++) {
        cout << "Nama proses: ";
        cin >> p[i].name;
        cout << "Burst time: ";
        cin >> p[i].burst;
        p[i].remaining = p[i].burst;
        p[i].waiting = 0;
        p[i].turnaround = 0;
        q.push(i);
    }

    int time = 0;
    cout << "\n=== Gantt Chart ===\n";
    while (!q.empty()) {
        int idx = q.front(); q.pop();

        int exec = std::min(p[idx].remaining, quantum);
        cout << time << " | " << p[idx].name << " | ";
        time += exec;
        p[idx].remaining -= exec;

        // Update waiting untuk proses lain yang masih belum selesai
        for (int i = 0; i < n; i++) {
            if (i != idx && p[i].remaining > 0) {
                p[i].waiting += exec;
            }
        }

        if (p[idx].remaining > 0) {
            q.push(idx); // proses belum selesai, masuk lagi ke antrian
        } else {
            p[idx].turnaround = time;
        }
    }
    cout << time << "\n\n";

    // Hitung rata-rata waktu tunggu
    double totalWait = 0;
    for (int i = 0; i < n; i++) {
        totalWait += p[i].waiting;
        cout << p[i].name << " - Waiting: " << p[i].waiting
             << ", Turnaround: " << p[i].turnaround << endl;
    }
    cout << "Rata-rata waktu tunggu: " << (totalWait / n) << endl;

    return 0;
}