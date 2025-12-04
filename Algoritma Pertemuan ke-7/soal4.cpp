// ...existing code...
#include <bits/stdc++.h>
using namespace std;

// Simple ANSI color helpers (works in VS Code terminal / Windows 10+)
// If colors don't show, run terminal that supports ANSI or enable VT processing.
const string RST = "\033[0m";
const string RED = "\033[31m";
const string GRN = "\033[32m";
const string YEL = "\033[33m";
const string BLU = "\033[34m";
const string MAG = "\033[35m";
const string CYN = "\033[36m";

void banner() {
    cout << CYN;
    cout << "=============================================\n";
    cout << "   _  _    _    _  __    _    _  _  _   _   \n";
    cout << "  | \\| |__| |__| |/ /_ _| |__| \\| | |_| |_ \n";
    cout << "  | .` / -_) / _` | ' \\` | / _` .` |  _|  _|\n";
    cout << "  |_|\\_\\___|_\\__,_|_|_/_|_|_\\__,_|\\_|\\__|\\__|\n";
    cout << "            Kalkulator Interaktif\n";
    cout << "=============================================\n" << RST;
}

void showMenu() {
    cout << GRN << "\nMenu:\n" << RST;
    cout << " 1) Penjumlahan (a + b)\n";
    cout << " 2) Pengurangan (a - b)\n";
    cout << " 3) Perkalian (a * b)\n";
    cout << " 4) Pembagian (a / b)\n";
    cout << " 5) Modulus (a % b) - integer\n";
    cout << " 6) Pangkat (a ^ b)\n";
    cout << " 7) Akar Kuadrat (sqrt(a))\n";
    cout << " 8) Faktorial (n!) - integer\n";
    cout << " 9) Lihat Riwayat\n";
    cout << " 0) Keluar\n";
}

long long factorial_int(int n) {
    if (n < 0) return -1;
    long long res = 1;
    for (int i = 2; i <= n; ++i) res *= i;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> history;
    banner();

    while (true) {
        showMenu();
        cout << BLU << "\nPilih opsi: " << RST;
        int opt;
        if (!(cin >> opt)) {
            cout << RED << "Input tidak valid. Keluar.\n" << RST;
            break;
        }
        if (opt == 0) {
            cout << MAG << "Terima kasih! Sampai jumpa.\n" << RST;
            break;
        }

        double a, b;
        long long ai;
        string entry;
        ostringstream out;

        switch (opt) {
            case 1:
                cout << "Masukkan a dan b: ";
                if (!(cin >> a >> b)) { cout << RED << "Input invalid\n" << RST; cin.clear(); cin.ignore(10000,'\n'); break; }
                out << a << " + " << b << " = " << (a + b);
                cout << GRN << out.str() << RST << "\n";
                history.push_back(out.str());
                break;
            case 2:
                cout << "Masukkan a dan b: ";
                if (!(cin >> a >> b)) { cout << RED << "Input invalid\n" << RST; cin.clear(); cin.ignore(10000,'\n'); break; }
                out << a << " - " << b << " = " << (a - b);
                cout << GRN << out.str() << RST << "\n";
                history.push_back(out.str());
                break;
            case 3:
                cout << "Masukkan a dan b: ";
                if (!(cin >> a >> b)) { cout << RED << "Input invalid\n" << RST; cin.clear(); cin.ignore(10000,'\n'); break; }
                out << a << " * " << b << " = " << (a * b);
                cout << GRN << out.str() << RST << "\n";
                history.push_back(out.str());
                break;
            case 4:
                cout << "Masukkan a dan b: ";
                if (!(cin >> a >> b)) { cout << RED << "Input invalid\n" << RST; cin.clear(); cin.ignore(10000,'\n'); break; }
                if (b == 0) { cout << RED << "Kesalahan: pembagian dengan nol.\n" << RST; break; }
                out << a << " / " << b << " = " << (a / b);
                cout << GRN << out.str() << RST << "\n";
                history.push_back(out.str());
                break;
            case 5:
                cout << "Masukkan dua bilangan bulat a b: ";
                {
                    long long ai1, ai2;
                    if (!(cin >> ai1 >> ai2)) { cout << RED << "Input invalid\n" << RST; cin.clear(); cin.ignore(10000,'\n'); break; }
                    if (ai2 == 0) { cout << RED << "Modulus dengan nol.\n" << RST; break; }
                    out << ai1 << " % " << ai2 << " = " << (ai1 % ai2);
                    cout << GRN << out.str() << RST << "\n";
                    history.push_back(out.str());
                }
                break;
            case 6:
                cout << "Masukkan a dan b (a^b): ";
                if (!(cin >> a >> b)) { cout << RED << "Input invalid\n" << RST; cin.clear(); cin.ignore(10000,'\n'); break; }
                out << a << " ^ " << b << " = " << pow(a, b);
                cout << GRN << out.str() << RST << "\n";
                history.push_back(out.str());
                break;
            case 7:
                cout << "Masukkan a: ";
                if (!(cin >> a)) { cout << RED << "Input invalid\n" << RST; cin.clear(); cin.ignore(10000,'\n'); break; }
                if (a < 0) { cout << RED << "Akar kuadrat bilangan negatif (kompleks) tidak didukung.\n" << RST; break; }
                out << "sqrt(" << a << ") = " << sqrt(a);
                cout << GRN << out.str() << RST << "\n";
                history.push_back(out.str());
                break;
            case 8:
                cout << "Masukkan n (bilangan bulat >= 0): ";
                if (!(cin >> ai)) { cout << RED << "Input invalid\n" << RST; cin.clear(); cin.ignore(10000,'\n'); break; }
                if (ai < 0 || ai > 20) { cout << YEL << "Untuk keamanan, n harus 0..20.\n" << RST; break; }
                out << ai << "! = " << factorial_int((int)ai);
                cout << GRN << out.str() << RST << "\n";
                history.push_back(out.str());
                break;
            case 9:
                cout << MAG << "\n=== Riwayat ===\n" << RST;
                if (history.empty()) cout << YEL << "(Kosong)\n" << RST;
                else {
                    for (size_t i = 0; i < history.size(); ++i) {
                        cout << i+1 << ") " << history[i] << "\n";
                    }
                }
                break;
            default:
                cout << RED << "Opsi tidak dikenal.\n" << RST;
        }

        cout << CYN << "\nTekan Enter untuk melanjutkan..." << RST;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

    return 0;
}
// ...existing code...