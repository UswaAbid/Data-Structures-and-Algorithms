#include <iostream>
#include <time.h>
using namespace std;

struct Node {
    int key;
    struct Node* left, *right;
};

// Create node
struct Node* newNode(int k) {
    Node* node = new Node;
    node->key = k;
    node->right = node->left = NULL;
    return node;
}

// Count the number of nodes
int countNumNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNumNodes(root->left) + countNumNodes(root->right);
}

// Check if the tree is a complete binary tree
bool checkComplete(struct Node* root, int index, int numberNodes) {
    if (root == NULL)
        return true;
    if (index >= numberNodes)
        return false;
    return checkComplete(root->left, 2 * index + 1, numberNodes) && checkComplete(root->right, 2 * index + 2, numberNodes);
}

void displayCBT(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " | ";
    }
    cout << endl;
}

void insertNode(int arr[], int& size, int value) {
    arr[size] = value; // Insert the value at the end of the array
    size++;
}


int main() {
    struct Node* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
   
    int node_count = countNumNodes(root);
    int index = 0;

    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    int size = sizeof(arr) / sizeof(arr[0]);
     cout << "\nOriginal tree:" << endl;
    displayCBT(arr, size);
     cout << endl;


    int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Check whether complete Binary tree\n";
        cout << "2. Insert element in complete binary tree\n";
        cout << "3. Array representation of Complete binary tree\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
         system("cls");
        

        switch (choice) {
            case 1:
                if (checkComplete(root, index, node_count))
                    cout << "\nThe tree is a complete binary tree\n";
                else
                    cout << "\nThe tree is not a complete binary tree\n";
                break;

            case 2:
                int value;
                cout << "\nEnter the element to insert: ";
                cin >> value;
                insertNode(arr, size, value);
                cout << "Value " << value << " inserted into the complete binary tree\n";
                break;

            case 3:
                cout << "\nComplete Binary Tree: ";
                displayCBT(arr, size);
                break;

            case 4:
                cout << "\nExiting the program. Goodbye!\n";
                return 0;

            default:
                cout << "Invalid choice. Please select a valid option.\n";
        }
    }
}

