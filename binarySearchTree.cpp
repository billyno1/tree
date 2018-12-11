#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int value;
    struct Node * left;
    struct Node * right;
    Node(int value):value(value), left(nullptr), right(nullptr){}
};

void insert(Node * node, int value) {
    if(!node->left && node->value > value) {
        node->left = new Node(value);   
    } else if (!node->right && node->value < value) {
        node->right = new Node(value);   
    } else if (node->value < value) {
        insert(node->right, value);   
    } else if (node->value > value) {
        insert(node->left, value);   
    } else {
        // value == node->value, just return   
    }
}
void printTree(Node *root) {
    cout << root->value << endl;
    cout << root->left->value << ", ";
    cout << root->right->value << endl;
    
    cout << root->left->left->value << " ";
    cout << root->left->right->value << ", ";
    cout << root->right->left->value << " ";
    cout << root->right->right->value << endl;
    
    cout << root->left->left->left->value << " ";
}
void deleteTree(Node * node) {
    if(!node) return;
    deleteTree(node->left);
    node->left = nullptr;
    deleteTree(node->right);
    node->right = nullptr;
    if(!node->left && !node->right) {
        delete node;
    }
}   
int main()
{
    
    Node *root = new Node(4);
    insert(root, 2);
    insert(root, 6);
    insert(root, 3);
    insert(root, 1);
    insert(root, 5);
    insert(root, 0);
    insert(root, 7);
    //printTreePreOrder(root);
    deleteTree(root);
    root = nullptr;
    //printTree(root);
    if(root==nullptr) cout << "EMPTY"<<endl;
    //printTreeInOrder(root);
    //printTreePostOrder(root);
    return 0;
}
