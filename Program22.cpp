#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue structure for level-order insertion
struct QueueNode {
    struct Node* node;
    struct QueueNode* next;
};

// Create a new tree node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Enqueue a node
void enqueue(struct QueueNode** front, struct QueueNode** rear, struct Node* node) {
    struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->node = node;
    temp->next = NULL;
    if (*rear == NULL)
        *front = *rear = temp;
    else {
        (*rear)->next = temp;
        *rear = temp;
    }
}

// Dequeue a node
struct Node* dequeue(struct QueueNode** front, struct QueueNode** rear) {
    if (*front == NULL)
        return NULL;
    struct QueueNode* temp = *front;
    struct Node* node = temp->node;
    *front = (*front)->next;
    if (*front == NULL)
        *rear = NULL;
    free(temp);
    return node;
}

// Insert node level by level (not BST)
struct Node* insertLevelOrder(struct Node* root, int value) {
    struct Node* newNode = createNode(value);

    // If tree is empty, new node is root
    if (root == NULL)
        return newNode;

    // Create a queue for level-order traversal
    struct QueueNode *front = NULL, *rear = NULL;
    enqueue(&front, &rear, root);

    while (front != NULL) {
        struct Node* temp = dequeue(&front, &rear);

        if (temp->left == NULL) {
            temp->left = newNode;
            break;
        } else
            enqueue(&front, &rear, temp->left);

        if (temp->right == NULL) {
            temp->right = newNode;
            break;
        } else
            enqueue(&front, &rear, temp->right);
    }

    return root;
}

// Inorder Traversal (Left → Root → Right)
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder Traversal (Root → Left → Right)
void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal (Left → Right → Root)
void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Main function
int main() {
    struct Node* root = NULL;
    int n, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insertLevelOrder(root, value);
    }

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\n");
    return 0;
}
