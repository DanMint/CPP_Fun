#include <iostream>
#include <vector>

using namespace std;

struct Queue {
    int tail = 0;
    int head = 0;
    int capacity = 0;
    int size = 0;
    int *Q;

    Queue() {
        tail = 0;
        head = 0;
        capacity = 0;
        size = 0;
    }
};

void enqueue(Queue *Q, int val) {
    if (Q->size == Q->capacity) {
        cerr << "Queue is full" << endl;
        return;
    }
    Q->Q[Q->tail] = val;
    Q->tail = (Q->tail + 1) % Q->capacity; 
    Q->size += 1;
}

int dequeue(Queue *Q) {
    if (Q->size == 0) {
        cerr << "Empty queue cannot dequeue" << endl;
        return -1; 
    }

    int val = Q->Q[Q->head];
    Q->head = (Q->head + 1) % Q->capacity; 
    Q->size -= 1;
    return val;
}

int main() {
    Queue Q;
    Q.capacity = 5;
    Q.Q = new int[Q.capacity];

    enqueue(&Q, 1);
    enqueue(&Q, 2);
    enqueue(&Q, 3);
    enqueue(&Q, 4);
    enqueue(&Q, 5);

    cout << dequeue(&Q) << endl;
    cout << dequeue(&Q) << endl;
    cout << dequeue(&Q) << endl;
    enqueue(&Q, 6);             
    cout << dequeue(&Q) << endl;
    cout << dequeue(&Q) << endl;
    cout << dequeue(&Q) << endl;

    
    cout << dequeue(&Q) << endl; 

    delete[] Q.Q; 

    return 0;
}
