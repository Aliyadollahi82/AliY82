//Ali Yadollahi 4011406161
#include <iostream>
using namespace std;

// Structure for Binary Tree Node
struct BTreeNode {
    int value;          // Value of the node
    BTreeNode* left;    // Pointer to the left child
    BTreeNode* right;   // Pointer to the right child
};

// Structure for Generic Tree Node
struct GTreeNode {
    int value;              // Value of the node
    GTreeNode* firstChild;  // Pointer to the first child
    GTreeNode* nextSibling; // Pointer to the next sibling
};

// Function to create a generic tree
GTreeNode* createGTree() {
    int value;
    cout << "Please provide the value of the node: ";
    cin >> value;

    GTreeNode* node = new GTreeNode;   // Create a new node
    node->value = value;                // Assign the provided value to the node
    node->firstChild = nullptr;         // Initialize first child pointer to null
    node->nextSibling = nullptr;        // Initialize next sibling pointer to null

    char select;
    
    // Check if the node has a child
    cout << "Does node " << value << " have any children (y/n)? ";
    cin >> select;

    if (select == 'y' || select == 'Y') {
        // Create a child and assign it to the first child pointer
        node->firstChild = createGTree();
    }

    // Check if the node has a sibling
    cout << "Does node " << value << " have any siblings (y/n)? ";
    cin >> select;

    if (select == 'y' || select == 'Y') {
        // Create a sibling and assign it to the next sibling pointer
        node->nextSibling = createGTree();
    }

    return node;    // Return the created node
}

// Function to convert a generic tree to a binary tree
BTreeNode* convertToBinaryTree(GTreeNode* genericNode) {
    if (genericNode == nullptr) {
        return nullptr;
    }
    
    BTreeNode* binaryNode = new BTreeNode;  // Create a new binary tree node
    
    binaryNode->value = genericNode->value; // Assign value from generic tree to binary tree node

    // Recursively convert the first child of generic node to left child of binary node
    binaryNode->left = convertToBinaryTree(genericNode->firstChild);

    // Recursively convert the next sibling of generic node to right child of binary node
    binaryNode->right = convertToBinaryTree(genericNode->nextSibling);

    return binaryNode;  // Return the created binary node
}

// Function to print the binary tree in inorder traversal
void printInOrder(BTreeNode* root) {
    if (root == nullptr) {
        return;
    }

    // Print the left subtree
    printInOrder(root->left);
    
    // Print the value of the root node
    cout << root->value << " ";
    
    // Print the right subtree
    printInOrder(root->right);
}

int main() {
    cout << "A quick tip: 'y' is for yes and 'n' is for no" << endl;
    
    // Take input from the user to create a generic tree
    GTreeNode* rootGeneric = createGTree();

    // Convert the generic tree to a binary tree
    BTreeNode* rootBinary = convertToBinaryTree(rootGeneric);

    // Print the binary tree in inorder traversal
    cout << "Inorder form of the binary tree: ";
    printInOrder(rootBinary);

    return 0;
}
