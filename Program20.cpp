#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Queue class
class Queue {
private:
    Node* front; // pointer to the front node
    Node* rear;  // pointer to the rear node

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Enqueue operation
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " enqueued to the queue.\n";
    }

    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        // if queue becomes empty
        if (front == nullptr) {
            rear = nullptr;
        }

        cout << temp->data << " dequeued from the queue.\n";
        delete temp;
    }

    // Peek front element
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
        } else {
            cout << "Front element is: " << front->data << "\n";
        }
    }

    // Display the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

// Main function
int main() {
    Queue q;
    int choice, value;

    while (true) {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}

