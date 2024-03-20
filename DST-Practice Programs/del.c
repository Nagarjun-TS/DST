#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the binary search tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary search tree
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Function to perform in-order traversal of the binary search tree
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to perform pre-order traversal of the binary search tree
void preOrderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Function to perform post-order traversal of the binary search tree
void postOrderTraversal(struct Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to display elements in the tree based on the given traversal method
void display(struct Node* root, int choice) {
    switch (choice) {
        case 1:
            printf("Elements in the tree (in-order traversal): ");
            inOrderTraversal(root);
            printf("\n");
            break;
        case 2:
            printf("Elements in the tree (pre-order traversal): ");
            preOrderTraversal(root);
            printf("\n");
            break;
        case 3:
            printf("Elements in the tree (post-order traversal): ");
            postOrderTraversal(root);
            printf("\n");
            break;
        default:
            printf("Invalid choice!\n");
    }
}

int main() {
    struct Node* root = NULL;
    int data, choice;

    // Constructing the binary search tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Enter your choice:\n1. In-order traversal\n2. Pre-order traversal\n3. Post-order traversal\n");
    scanf("%d", &choice);

    // Displaying the elements in the tree based on the chosen traversal method
    display(root, choice);

    return 0;
}
