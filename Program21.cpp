#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Doubly Linked List structure
struct DoublyLinkedList {
    Node* head;

    // Constructor equivalent
    DoublyLinkedList() {
        head = nullptr;
    }

    // Insert at beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr)
            head->prev = newNode;

        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Delete node by value
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        // Find node with matching value
        while (temp != nullptr && temp->data != value)
            temp = temp->next;

        if (temp == nullptr) {
            cout << "Value " << value << " not found in list\n";
            return;
        }

        if (temp == head)
            head = temp->next;

        if (temp->next != nullptr)
            temp->next->prev = temp->prev;

        if (temp->prev != nullptr)
            temp->prev->next = temp->next;

        delete temp;
        cout << "Node with value " << value << " deleted\n";
    }

    // Display forward
    void displayForward() {
        Node* temp = head;
        cout << "List (Forward): ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Display backward
    void displayBackward() {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        cout << "List (Backward): ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

// Main function
int main() {
    DoublyLinkedList dll;

    dll.insertAtEnd(10);
    dll.insertAtEnd(20);
    dll.insertAtEnd(30);
    dll.displayForward();
    dll.displayBackward();

    dll.insertAtBeginning(5);
    dll.displayForward();

    dll.deleteNode(20);
    dll.displayForward();
    dll.displayBackward();

    return 0;
}

