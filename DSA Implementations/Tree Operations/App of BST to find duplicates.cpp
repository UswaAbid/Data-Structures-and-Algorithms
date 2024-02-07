
 #include <iostream>

using namespace std;

// Structure for a tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(NULL), right(NULL) {}
};

// Function to insert a node into a BST
TreeNode* insert(TreeNode* root, int value) {
    if (root == NULL) {
        return new TreeNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to check if a value already exists in a BST
bool contains(TreeNode* root, int value) {
    if (root == NULL) {
        return false;
    }

    if (value == root->data) {
        return true;
    } else if (value < root->data) {
        return contains(root->left, value);
    } else {
        return contains(root->right, value);
    }
}

// Function to find duplicates in an array using a BST
void findDuplicates(int arr[], int size) {
    TreeNode* root = NULL;

    cout << "\n Duplicate elements in the array: ";
    for (int i = 0; i < size; ++i) {
        // If the element already exists in the BST, it's a duplicate
        if (contains(root, arr[i])) {
            cout << arr[i] << " ";
        } else {
            // Insert the element into the BST for future checking
            root = insert(root, arr[i]);
        }
    }

    cout << endl;
}

int main() {
    int arr[] = {4, 2, 8, 6, 2, 7, 1, 4, 9, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    findDuplicates(arr, size);

    return 0;
}

