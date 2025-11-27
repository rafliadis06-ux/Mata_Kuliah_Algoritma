#include <iostream>
using namespace std;

#define MAX 100

// Struktur Queue
struct Queue {
    char data[MAX];
    int front;
    int rear;
};

// Inisialisasi Queue
void init(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Cek apakah Queue kosong
bool isEmpty(Queue *q) {
    if (q->front == -1) {
        return true;
    }
    return false;
}

// Cek apakah Queue penuh
bool isFull(Queue *q) {
    if (q->rear == MAX - 1) {
        return true;
    }
    return false;
}

// Insert elemen ke Queue
void insert(Queue *q, char value) {
    if (isFull(q)) {
        cout << "Queue penuh!" << endl;
    } else {
        if (isEmpty(q)) {
            q->front = 0;
        }
        q->rear++;
        q->data[q->rear] = value;
        cout << "Inserted: " << value << endl;
    }
}

// Remove elemen dari Queue
void remove(Queue *q) {
    if (isEmpty(q)) {
        cout << "Queue kosong!" << endl;
    } else {
        char value = q->data[q->front];
        cout << "Removed: " << value << endl;
        
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front++;
        }
    }
}

// Tampilkan isi Queue
void display(Queue *q) {
    if (isEmpty(q)) {
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Isi Queue: ";
        for (int i = q->front; i <= q->rear; i++) {
            cout << q->data[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    Queue q;
    init(&q);
    
    char karakter;
    int jumlah;
    
    cout << "=== Program Queue Character ===" << endl;
    cout << endl;
    
    // 1. Input dari pengguna
    cout << "Berapa karakter yang ingin dimasukkan? ";
    cin >> jumlah;
    
    cout << "Masukkan " << jumlah << " karakter:" << endl;
    for (int i = 0; i < jumlah; i++) {
        cout << "Karakter ke-" << (i+1) << ": ";
        cin >> karakter;
        insert(&q, karakter);
    }
    cout << endl;
    
    // 2. Menampilkan isi queue
    cout << "Isi Queue setelah input:" << endl;
    display(&q);
    cout << endl;
    
    // 3. Menghapus elemen
    int hapus;
    cout << "Berapa elemen yang ingin dihapus? ";
    cin >> hapus;
    
    cout << "Menghapus " << hapus << " elemen:" << endl;
    for (int i = 0; i < hapus; i++) {
        remove(&q);
    }
    cout << endl;
    
    // 4. Menampilkan isi queue kembali
    cout << "Isi Queue setelah penghapusan:" << endl;
    display(&q);
    
    return 0;
}