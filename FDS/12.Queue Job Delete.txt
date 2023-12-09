#include <iostream>
#define MAX 10

using namespace std;

struct QueueStruct {
    int data[MAX];
    int front, rear;
};

class Queue {
    QueueStruct q;

public:
    Queue() {
        q.front = q.rear = -1;
    }

    int isEmpty() {
        return (q.front == q.rear) ? 1 : 0;
    }

    int isFull() {
        return (q.rear == MAX - 1) ? 1 : 0;
    }

    void enqueue(int x) {
        q.data[++q.rear] = x;
    }

    int dequeue() {
        return q.data[++q.front];
    }

    void display() {
        int i;
        cout << "\n";
        for (i = q.front + 1; i <= q.rear; i++)
            cout << q.data[i] << " ";
    }
};

int main() {
    Queue obj;
    int ch, x;

    do {
        cout << "\n1. Insert Job\n2. Delete Job\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                if (!obj.isFull()) {
                    cout << "\nEnter data: ";
                    cin >> x;
                    obj.enqueue(x);
                    cout << endl;
                } else {
                    cout << "Queue is overflow!!!\n\n";
                }
                break;
            case 2:
                if (!obj.isEmpty()) {
                    cout << "\nDeleted Element = " << obj.dequeue() << endl;
                    cout << "\nRemaining Jobs: ";
                    obj.display();
                } else {
                    cout << "\nQueue is underflow!!!\n\n";
                }
                break;
            case 3:
                if (!obj.isEmpty()) {
                    cout << "\nQueue contains: ";
                    obj.display();
                } else {
                    cout << "\nQueue is empty!!!\n\n";
                }
                break;
            case 4:
                cout << "\nExiting Program.....";
                break;
            default:
                cout << "\nInvalid choice! Please enter a valid choice.";
        }
    } while (ch != 4);

    return 0;
}
