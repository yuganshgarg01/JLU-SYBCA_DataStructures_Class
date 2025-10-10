#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertAtEnd(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert at given position (1-based index)
void insertAtPosition(Node*& head, int value, int position) {
    if (position == 1) {
        insertAtBeginning(head, value);
        return;
    }

    Node* newNode = createNode(value);
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position out of range!" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete head
void deleteHead(Node*& head) {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

// Delete at given position (1-based index)
void deleteAtPosition(Node*& head, int position) {
    if (head == nullptr) return;

    if (position == 1) {
        deleteHead(head);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != nullptr; i++) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Position out of range!" << endl;
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}

// Delete last node
void deleteLast(Node*& head) {
    if (head == nullptr) return;

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}

// Print linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Main function to test
int main() {
    Node* head = nullptr;

    // Insert at beginning
    insertAtBeginning(head, 30);
    insertAtBeginning(head, 20);
    insertAtBeginning(head, 10);
    printList(head); // 10 -> 20 -> 30 -> NULL

    // Insert at end
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);
    printList(head); // 10 -> 20 -> 30 -> 40 -> 50 -> NULL

    // Insert at position
    insertAtPosition(head, 25, 3);
    printList(head); // 10 -> 20 -> 25 -> 30 -> 40 -> 50 -> NULL

    // Delete head
    deleteHead(head);
    printList(head); // 20 -> 25 -> 30 -> 40 -> 50 -> NULL

    // Delete at position
    deleteAtPosition(head, 3);
    printList(head); // 20 -> 25 -> 40 -> 50 -> NULL

    // Delete last
    deleteLast(head);
    printList(head); // 20 -> 25 -> 40 -> NULL

    return 0;
}

