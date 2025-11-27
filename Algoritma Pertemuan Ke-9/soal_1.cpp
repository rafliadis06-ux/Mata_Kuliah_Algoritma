#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

class Queue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;
    int count;

public:
    // Inisialisasi queue
    void init() {
        front = 0;
        rear = -1;
        count = 0;
        cout << "Queue berhasil diinisialisasi!" << endl;
    }

    // Cek apakah queue kosong
    bool isEmpty() {
        return (count == 0);
    }

    // Cek apakah queue penuh
    bool isFull() {
        return (count == MAX_SIZE);
    }

    // Menambahkan elemen ke queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue penuh! Tidak dapat menambahkan " << value << endl;
            return;
        }
        
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = value;
        count++;
        cout << "Elemen " << value << " berhasil ditambahkan ke queue" << endl;
    }

    // Menghapus elemen dari queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue kosong! Tidak ada elemen yang dapat dihapus" << endl;
            return;
        }
        
        int value = arr[front];
        front = (front + 1) % MAX_SIZE;
        count--;
        cout << "Elemen " << value << " berhasil dihapus dari queue" << endl;
    }

    // Menampilkan semua elemen dalam queue
    void display() {
        if (isEmpty()) {
            cout << "Queue kosong!" << endl;
            return;
        }
        
        cout << "Isi Queue: ";
        int idx = front;
        for (int i = 0; i < count; i++) {
            cout << arr[idx] << " ";
            idx = (idx + 1) % MAX_SIZE;
        }
        cout << endl;
        cout << "Jumlah elemen: " << count << "/" << MAX_SIZE << endl;
    }
};

int main() {
    Queue q;
    int pilihan, nilai;

    q.init();

    do {
        cout << "\n=== MENU QUEUE ===" << endl;
        cout << "1. Enqueue (Tambah elemen)" << endl;
        cout << "2. Dequeue (Hapus elemen)" << endl;
        cout << "3. Display (Tampilkan queue)" << endl;
        cout << "4. Cek isEmpty" << endl;
        cout << "5. Cek isFull" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                q.enqueue(nilai);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                if (q.isEmpty()) {
                    cout << "Queue kosong" << endl;
                } else {
                    cout << "Queue tidak kosong" << endl;
                }
                break;
            case 5:
                if (q.isFull()) {
                    cout << "Queue penuh" << endl;
                } else {
                    cout << "Queue tidak penuh" << endl;
                }
                break;
            case 6:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 6);

    return 0;
}