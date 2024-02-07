#include <iostream>
#include <time.h>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void display(Node* root) {
    if (root == NULL) {
        return;
    }
    display(root->left);
    cout << root->data << " ";
    display(root->right);
}


     Node* insert(Node* root, int value) {
    if (root == NULL) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

void treeToArray(Node* root, int arr[], int& index) {
    if (root == NULL) {
        return;
    }
    treeToArray(root->left, arr, index);
    arr[index++] = root->data;
    treeToArray(root->right, arr, index);
}
   
// Function to perform an inorder traversal using a stack
void inorderTraversal(Node* root) {
    stack<Node*> s;
    Node* current = root;

    while (current != NULL || !s.empty()) {
        while (current != NULL) {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();
        cout << current->data << " ";

        current = current->right;
    }
}

// Function to perform a preorder traversal using a stack
void preorderTraversal(Node* root) {
    if (root == NULL) return;

    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* current = s.top();
        s.pop();
        cout << current->data << " ";

        if (current->right != NULL) {
            s.push(current->right);
        }
        if (current->left != NULL) {
            s.push(current->left);
        }
    }
}

// Function to perform a postorder traversal using a stack
void postorderTraversal(Node* root) {
    if (root == NULL) return;

   stack<Node*>  s1;
    stack<Node*>  s2;

    s1.push(root);

    while (!s1.empty()) {
        Node* current = s1.top();
        s1.pop();
        s2.push(current);

        if (current->left != NULL) {
            s1.push(current->left);
        }
        if (current->right != NULL) {
            s1.push(current->right);
        }
    }

    while (!s2.empty()) {
        Node* current = s2.top();
        s2.pop();
        cout << current->data << " ";
    }
}
   
   
   
int main() {
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    
     cout << "Original binary tree:" << endl;
     display(root);
     cout << endl;

    int choice;
    int arr[6];
    int index = 0;

    while (true) {
        cout << "\nOptions:\n";
        cout << "1. Insert elements in tree\n";
        cout << "2. Array representation of binary tree\n";
        cout << "3. Binary Tree Traversal\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        system("cls");

       

        switch (choice) {
            case 1:
                 int value;
                cout << "\nEnter the value to insert: ";
                cin >> value;
                root = insert(root, value);
                cout << "Binary Tree after inserting new elements:" << endl;
                display(root);
                cout << endl;

                break;

            case 2:
                treeToArray(root, arr, index);
                cout << "\nArray Representation of Binary Tree: "<<endl;
                for (int i = 0; i < index; i++) {
                    cout << arr[i] << " | ";
                }
                cout << endl;
                break;
            case 3:
            	    cout << " \n Inorder traversal: ";
                    inorderTraversal(root);
                    cout << "\n";

                 cout << " Preorder traversal: ";
                 preorderTraversal(root);
                 cout << "\n";

                 cout << " Postorder traversal: ";
                 postorderTraversal(root);
                 cout << "\n";
                 break;
            case 4:
                cout << "\nExiting the program. Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice. Please select a valid option." << endl;
                break;
        }
    }

    return 0;
}

