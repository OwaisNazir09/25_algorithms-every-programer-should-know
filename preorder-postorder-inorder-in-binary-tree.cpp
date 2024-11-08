#include <iostream>
using namespace std;

// Node class representing a single node in a binary tree
class node {
public:
    int data;         // Data contained in the node
    node* left;       // Pointer to the left child node
    node* right;      // Pointer to the right child node

    // Constructor to initialize a node with a given data value.
    // Left and right children are initialized to NULL.
    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to build a binary tree by taking input from the user
// Returns a pointer to the root node of the constructed tree
node* treebuilder(node* root) {
    cout << "Enter data for node (enter 00 for NULL): ";
    int data;
    cin >> data;
    
    // '00' is used as a marker to indicate NULL nodes
    if (data == 00) {
        return NULL;
    }
    
    // Create a new node with the input data
    root = new node(data);
  
    // Recursively build the left subtree
    cout << "Enter the data for the node's left part" << endl;
    root->left = treebuilder(root->left);

    // Recursively build the right subtree
    cout << "Enter data for node's right part" << endl;
    root->right = treebuilder(root->right);

    return root;
}

// Function to perform an inorder traversal (left, root, right) of the binary tree
// and print each node's data. This outputs nodes in ascending order for BSTs.
void inorder(node* root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);       // Traverse the left subtree
    cout << root->data << endl; // Visit the root node
    inorder(root->right);      // Traverse the right subtree
}

// Function to perform a preorder traversal (root, left, right) of the binary tree
// and print each node's data. This is useful for creating a copy of the tree.
void preorder(node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->data << endl; // Visit the root node
    preorder(root->left);      // Traverse the left subtree
    preorder(root->right);     // Traverse the right subtree
}

// Function to perform a postorder traversal (left, right, root) of the binary tree
// and print each node's data. This is useful for deleting or freeing nodes.
void postorder(node* root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);     // Traverse the left subtree
    postorder(root->right);    // Traverse the right subtree
    cout << root->data << endl; // Visit the root node
}

// Main function to drive the program
int main() {
    node* root = NULL; // Initialize root pointer to NULL
    
    // Build the binary tree by calling treebuilder and capturing the root
    root = treebuilder(root);

    // Perform inorder traversal and print the tree's nodes in inorder
    cout << "Traversed tree in inorder:" << endl;
    inorder(root);

    // Perform postorder traversal and print the tree's nodes in postorder
    cout << "Traversed tree in postorder:" << endl;
    postorder(root);

    // Perform preorder traversal and print the tree's nodes in preorder
    cout << "Traversed tree in preorder:" << endl;
    preorder(root);

    return 0;
}
