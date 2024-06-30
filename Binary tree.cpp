//AliYadollahi 4011406161


#include <iostream>

using namespace std;

//creating binary tree
struct BTreeNode {
    int             value;
    BTreeNode*       left;
    BTreeNode*      right;
};

//creating generic tree
struct GTreeNode {
    int              value;
    GTreeNode*  firstChild;
    GTreeNode* nextSibling;
};

//taking the generic tree from the user
GTreeNode* createGTree() {
    int value;
    cout << "Please provide the value of the node: ";
    cin >> value;

    GTreeNode* node = new GTreeNode;
    node->value = value;
    node->firstChild = nullptr;
    node->nextSibling = nullptr;

    char select;
    
    //check if the node has a child
    cout << "Does node " << value << " have any children (y/n)? ";
    cin >> select;

    if (select == 'y' || select == 'Y') {
    	//create a child
        node->firstChild = createGTree();
    }

    //check if the node has a sibling
    cout << "Does node " << value << " have any siblings (y/n)? ";
    cin >> select;

    if (select == 'y' || select == 'Y') {
    	//create a sibiling
        node->nextSibling = createGTree();
    }

    return node;
}

//converting the generic tree to binary
BTreeNode* convertToBinaryTree(GTreeNode* genericNode) {
    if (genericNode == nullptr) {
        return nullptr;
    }
	//create a new binary tree
    BTreeNode* binaryNode = new BTreeNode;
    
    binaryNode->value = genericNode->value;
//convert the first child to the left child
    binaryNode->left = convertToBinaryTree(genericNode->firstChild);
//convert the next sibling to the right child
    binaryNode->right = convertToBinaryTree(genericNode->nextSibling);

    return binaryNode;
}

//printing the binary tree using inorder paymaesh
void printInOrder(BTreeNode* root) {
    if (root == nullptr) {
        return;
    }

    printInOrder(root->left);
    cout << root->value << " ";
    printInOrder(root->right);
}

int main() {
	cout<<"a quick tip : 'y' is for yes and 'n' is for no"<<endl;
	//take the generic tree from the user
    GTreeNode* rootGeneric = createGTree();
	 // Convert the generic tree to a binary tree
    BTreeNode* rootBinary = convertToBinaryTree(rootGeneric);
	//printing the resault
    cout << "Inorder form of the binary tree: ";
    printInOrder(rootBinary);


    return 0;
}
