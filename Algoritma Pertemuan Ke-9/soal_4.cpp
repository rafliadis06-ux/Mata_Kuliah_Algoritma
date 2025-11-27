#include <iostream>
using namespace std;

#define MAX 100

// Struktur Pelanggan
struct Pelanggan {
    int nomorAntrian;
    int lamaPelayanan; // dalam detik
};

// Struktur Queue
struct Queue {
    Pelanggan data[MAX];
    int front;
    int rear;
    int count;
};

// Inisialisasi Queue
void init(Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

// Cek apakah Queue kosong
bool isEmpty(Queue *q) {
    return (q->count == 0);
}

// Cek apakah Queue penuh
bool isFull(Queue *q) {
    return (q->count == MAX);
}

// Tambah pelanggan (Enqueue)
void enqueue(Queue *q, int nomorAntrian, int lamaPelayanan) {
    if (isFull(q)) {
        cout << "Antrian penuh!" << endl;
    } else {
        q->rear = (q->rear + 1) % MAX;
        q->data[q->rear].nomorAntrian = nomorAntrian;
        q->data[q->rear].lamaPelayanan = lamaPelayanan;
        q->count++;
        cout << "Pelanggan nomor " << nomorAntrian << " berhasil ditambahkan!" << endl;
        cout << "Estimasi waktu pelayanan: " << lamaPelayanan << " detik" << endl;
    }
}

// Layani pelanggan (Dequeue)
void dequeue(Queue *q) {
    if (isEmpty(q)) {
        cout << "Antrian kosong! Tidak ada pelanggan." << endl;
    } else {
        Pelanggan p = q->data[q->front];
        cout << "Melayani pelanggan nomor " << p.nomorAntrian << endl;
        cout << "Waktu pelayanan: " << p.lamaPelayanan << " detik" << endl;
        cout << "Pelanggan selesai dilayani!" << endl;
        q->front = (q->front + 1) % MAX;
        q->count--;
    }
}

// Tampilkan pelanggan yang sedang menunggu
void tampilkanAntrian(Queue *q) {
    if (isEmpty(q)) {
        cout << "Antrian kosong!" << endl;
    } else {
        cout << "=== Daftar Pelanggan Menunggu ===" << endl;
        cout << "No.\tNomor Antrian\tLama Pelayanan" << endl;
        cout << "----------------------------------------" << endl;
        
        int pos = q->front;
        for (int i = 0; i < q->count; i++) {
            cout << (i+1) << "\t";
            cout << q->data[pos].nomorAntrian << "\t\t";
            cout << q->data[pos].lamaPelayanan << " detik" << endl;
            pos = (pos + 1) % MAX;
        }
        cout << "----------------------------------------" << endl;
    }
}

// Tampilkan jumlah pelanggan
void tampilkanJumlah(Queue *q) {
    cout << "Jumlah pelanggan dalam antrian: " << q->count << endl;
}

// Tampilkan menu
void tampilkanMenu() {
    cout << "\n=== SIMULASI ANTRIAN KASIR ===" << endl;
    cout << "1. Tambah Pelanggan (Enqueue)" << endl;
    cout << "2. Layani Pelanggan (Dequeue)" << endl;
    cout << "3. Tampilkan Pelanggan yang Menunggu" << endl;
    cout << "4. Tampilkan Jumlah Pelanggan" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilih menu: ";
}

int main() {
    Queue q;
    init(&q);
    
    int pilihan;
    int nomorAntrian = 1; // counter untuk nomor antrian
    int lamaPelayanan;
    
    do {
        tampilkanMenu();
        cin >> pilihan;
        cout << endl;
        
        switch(pilihan) {
            case 1:
                cout << "Masukkan lama pelayanan (detik): ";
                cin >> lamaPelayanan;
                enqueue(&q, nomorAntrian, lamaPelayanan);
                nomorAntrian++;
                break;
                
            case 2:
                dequeue(&q);
                break;
                
            case 3:
                tampilkanAntrian(&q);
                break;
                
            case 4:
                tampilkanJumlah(&q);
                break;
                
            case 5:
                cout << "Terima kasih! Program selesai." << endl;
                break;
                
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
        
    } while(pilihan != 5);
    
    return 0;
}