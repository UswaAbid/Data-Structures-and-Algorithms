#include <iostream>

using namespace std;

// Structure for a tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(NULL), right(NULL) {}
};

// Function to check whether a binary tree is complete
bool isCompleteBinaryTree(TreeNode* root) {
    if (root == NULL)
        return true;

    const int MAX_NODES = 100;  // Assuming a maximum of 100 nodes in the tree
    TreeNode* queue[MAX_NODES];
    int front = 0, rear = 0;
    bool nonFullNodeFound = false;

    queue[rear++] = root;

    while (front < rear) {
        TreeNode* current = queue[front++];

        // If a non-full node is found, all subsequent nodes must be leaf nodes
        if (current == NULL) {
            nonFullNodeFound = true;
        } else {
            if (nonFullNodeFound)
                return false;

            // Enqueue left and right children
            if (current->left != NULL)
                queue[rear++] = current->left;
            if (current->right != NULL)
                queue[rear++] = current->right;
        }
    }

    return true;
}

int main() {
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    /*
        The binary tree will look like this:
              1
            /   \
           2     3
          / \   /
         4   5 6
    */

    if (isCompleteBinaryTree(root)) {
        cout << "\nThe binary tree is a complete binary tree." << endl;
    } else {
        cout << "\nThe binary tree is not a complete binary tree." << endl;
    }

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

