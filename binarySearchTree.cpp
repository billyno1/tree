
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
    if(!node->left && node->value > value)) {
        node->left = new Node(value);   
    } else if (!node->right && node->value < value)) {
        node->right = new Node(value);   
    } else if (node->value < value) {
        insert(node->right, value);   
    } else if (node->value > value) {
        insert(node->left, value);   
    } else {
        // value == node->value, just return   
    }
}
int main()
{
    
    Node *root = new Node(0);
    //insertTreeBinary_I(root, 0);
    insertTree(root, 1);
    insertTree(root, 2);
    insertTree(root, 3);
    insertTree(root, 4);
    insertTree(root, 5);
    insertTree(root, 6);
    insertTree(root, 7);
    //printTreePreOrder(root);
    //printTree(root);
    //printTreeInOrder(root);
    printTreePostOrder(root);
    return 0;
}
