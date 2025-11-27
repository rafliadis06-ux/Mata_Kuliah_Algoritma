#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cout << "Masukkan tiga angka: ";
    cin >> a >> b >> c;

    int max;
    if (a > b && a > c) max = a;
    else if (b > a && b > c) max = b;
    else max = c;

    cout << "Bilangan terbesar adalah: " << max << endl;
    return 0;
}