#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

// Definisi struct
struct Mahasiswa {
    string nama;
    float nilai_akhir;
};

void tampilTabel(const Mahasiswa mhs[], int n) {
    const int colNo = 4;      // e.g. '+---+'
    const int colNama = 32;   // width for Nama column including padding
    const int colNilai = 14;  // width for Nilai column including padding

    auto printSep = [&](void) {
        cout << "+" << string(colNo, '-') << "+" << string(colNama, '-') << "+" << string(colNilai, '-') << "+\n";
    };

    auto center = [&](const string &s, int width) {
        if ((int)s.size() >= width) return s.substr(0, width);
        int left = (width - (int)s.size()) / 2;
        int right = width - (int)s.size() - left;
        return string(left, ' ') + s + string(right, ' ');
    };

    auto truncate = [&](const string &s, int width) {
        if ((int)s.size() <= width) return s + string(width - s.size(), ' ');
        if (width > 3) return s.substr(0, width-3) + "...";
        return s.substr(0, width);
    };

    printSep();
    // Header row (centered)
    cout << "|" << center("No", colNo) << "|" << center("Nama", colNama) << "|" << center("Nilai Akhir", colNilai) << "|\n";
    printSep();

    for (int i = 0; i < n; ++i) {
        // No column (right aligned in 2 spaces)
        cout << "|" << setw(colNo) << right << (i+1);

        // Nama column (truncate if too long, left aligned)
        cout << "|" << left << truncate(mhs[i].nama, colNama);

        // Nilai column (right aligned, 2 decimals)
        std::ostringstream oss;
        oss << fixed << setprecision(2) << mhs[i].nilai_akhir;
        cout << "|" << setw(colNilai) << right << oss.str() << "|\n";
    }

    printSep();
}

int main() {
    Mahasiswa mhs[5];   // array of struct untuk 5 mahasiswa
    float total = 0.0;

    // Input data mahasiswa
    for (int i = 0; i < 5; i++) {
        cout << "Masukkan Nama Mahasiswa ke-" << i+1 << " : ";
        getline(cin, mhs[i].nama);
        cout << "Masukkan Nilai Akhir       : ";
    cin >> mhs[i].nilai_akhir;
    // membersihkan buffer agar getline berikutnya tidak terlewat
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        total += mhs[i].nilai_akhir;
        cout << endl;
    }

    // Hitung rata-rata
    float rata_rata = total / 5;

    // Tampilkan hasil dalam bentuk tabel
    tampilTabel(mhs, 5);

    cout << "\nRata-rata Nilai Kelas: " << rata_rata << endl;
    return 0;
}