#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;       // data part
    Node* next;     // pointer to the next node
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node;   // allocate memory
    newNode->data = value;      // set data
    newNode->next = nullptr;    // next is null initially
    return newNode;
}

int main() {
    // Create first node (head)
    Node* head = createNode(10);

    // Create second node
    Node* second = createNode(20);
    head->next = second;  // link first node to second

    // Create third node
    Node* third = createNode(30);
    second->next = third; // link second to third

    // Traverse and print linked list
    Node* temp = head;  // start from head
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next; // move to next node
    }
    cout << "NULL" << endl;

    return 0;
}

