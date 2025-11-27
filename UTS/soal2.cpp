#include <iostream>
using namespace std;

int main() {
    int arr[10], key;
    cout << "Masukkan 10 angka: ";
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    cout << "Masukkan angka yang dicari: ";
    cin >> key;

    bool found = false;
    int pos;
    for (int i = 0; i < 10; i++) {
        if (arr[i] == key) {
            found = true;
            pos = i;
            break;
        }
    }

    if (found) cout << "Data ditemukan di indeks ke-" << pos << endl;
    else cout << "Data tidak ditemukan" << endl;

    return 0;
}