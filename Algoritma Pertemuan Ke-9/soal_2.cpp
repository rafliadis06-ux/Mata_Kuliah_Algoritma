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
    
    cout << "=== Program Queue Character ===" << endl;
    cout << endl;
    
    // Mengisi queue dengan 'A', 'R', 'I', 'F'
    cout << "1. Mengisi Queue:" << endl;
    insert(&q, 'A');
    insert(&q, 'R');
    insert(&q, 'I');
    insert(&q, 'F');
    cout << endl;
    
    // Menampilkan isi queue
    cout << "2. Tampilkan Queue:" << endl;
    display(&q);
    cout << endl;
    
    // Menghapus 2 elemen
    cout << "3. Hapus 2 elemen:" << endl;
    remove(&q);
    remove(&q);
    cout << endl;
    
    // Menampilkan isi queue kembali
    cout << "4. Tampilkan Queue lagi:" << endl;
    display(&q);
    
    return 0;
}