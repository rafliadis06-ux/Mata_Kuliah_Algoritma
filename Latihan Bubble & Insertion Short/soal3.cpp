#include <iostream>
using namespace std;

// Fungsi Bubble Sort
int bubbleSort(int arr[], int n) {
    int langkah = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            langkah++; // setiap perbandingan dihitung
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return langkah;
}

// Fungsi Insertion Sort
int insertionSort(int arr[], int n) {
    int langkah = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            langkah++; // setiap perbandingan dihitung
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
    return langkah;
}

// Fungsi tampilkan array
void tampilkanArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Masukkan jumlah data: ";
    cin >> n;

    int data[100]; // kapasitas maksimal 100 data
    cout << "Masukkan " << n << " angka: ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    // Salin array untuk kedua algoritma
    int arrBubble[100], arrInsertion[100];
    for (int i = 0; i < n; i++) {
        arrBubble[i] = data[i];
        arrInsertion[i] = data[i];
    }

    cout << "\nData sebelum diurutkan: ";
    tampilkanArray(data, n);

    // Bubble Sort
    int langkahBubble = bubbleSort(arrBubble, n);
    cout << "\nHasil Bubble Sort (Ascending): ";
    tampilkanArray(arrBubble, n);
    cout << "Jumlah langkah/perbandingan Bubble Sort: " << langkahBubble << endl;

    // Insertion Sort
    int langkahInsertion = insertionSort(arrInsertion, n);
    cout << "\nHasil Insertion Sort (Ascending): ";
    tampilkanArray(arrInsertion, n);
    cout << "Jumlah langkah/perbandingan Insertion Sort: " << langkahInsertion << endl;

    return 0;
}