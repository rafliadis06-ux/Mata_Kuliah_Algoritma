#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah proses: ";
    cin >> n;

    // Asumsi arrival time semua proses = 0 (sesuai modul)
    int pid[100];      // ID proses P1, P2, ...
    int bt[100];       // burst time setiap proses
    int rem_bt[100];   // sisa burst time setiap proses
    int ct[100] = {0}; // completion time setiap proses

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cout << "Masukkan burst time untuk P" << pid[i] << " : ";
        cin >> bt[i];
        rem_bt[i] = bt[i];
    }

    int quantum;
    cout << "Masukkan quantum time: ";
    cin >> quantum;

    // Variabel untuk simulasi dan Gantt Chart
    const int MAX_SEG = 1000;    // maksimum potongan eksekusi
    int segProc[MAX_SEG];        // proses ke-berapa yang dieksekusi
    int segStart[MAX_SEG];       // waktu mulai segmen
    int segEnd[MAX_SEG];         // waktu selesai segmen
    int segCount = 0;

    int t = 0; // current time (waktu saat ini)
    while (true) {
        bool done = true;

        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = false;           // masih ada proses yang belum selesai
                int start = t;          // waktu mulai segmen ini

                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t += rem_bt[i];
                    rem_bt[i] = 0;
                    ct[i] = t;          // proses selesai, catat completion time
                }

                if (segCount < MAX_SEG) {
                    segProc[segCount]  = pid[i];
                    segStart[segCount] = start;
                    segEnd[segCount]   = t;
                    segCount++;
                }
            }
        }

        if (done) break; // semua proses selesai
        
    }
    // Hitung WT dan TAT (arrival time = 0, jadi TAT = CT, WT = TAT - BT)
    int wt[100], tat[100];
    double total_wt = 0.0, total_tat = 0.0;

    for (int i = 0; i < n; i++) {
        tat[i] = ct[i];          // turnaround time
        wt[i]  = tat[i] - bt[i]; // waiting time
        total_wt  += wt[i];
        total_tat += tat[i];
    }

    // Tabel proses
    cout << "\nTabel Proses (Round Robin)\n";
    cout << "Proses\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << pid[i] << "\t"
             << bt[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << "\n";
    }

    cout << fixed << setprecision(2);
    cout << "\nRata-rata waktu tunggu = " << (total_wt / n) << endl;
    cout << "Rata-rata turn around time = " << (total_tat / n) << endl;

    // Tabel Gantt Chart (urutan eksekusi)
    cout << "\nTabel Gantt Chart (urutan eksekusi CPU):\n";
    cout << "No\tProses\tMulai\tSelesai\n";
    for (int i = 0; i < segCount; i++) {
        cout << (i + 1) << "\tP" << segProc[i]
             << "\t" << segStart[i]
             << "\t" << segEnd[i] << "\n";
    }
    return 0;
}