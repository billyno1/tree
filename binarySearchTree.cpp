
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int value;
    Node * left;
    Node * right;
    Node * parent;
    Node(int value):value(value), left(nullptr), right(nullptr), parent(nullptr){}
};

class BST{
    public:    
    Node * root;
    BST(int value) {
        root = new Node(value);
    }

    void printTree() {
        cout << root->value << endl;
        cout << root->left->value << ", ";
        cout << root->right->value << endl;
        
        cout << root->left->left->value << " ";
        cout << root->left->right->value << ", ";
        cout << root->right->left->value << " ";
        cout << root->right->right->value << endl;
        
        cout << root->left->left->left->value << " ";
    }
    
    void deleteTree() {
        return deleteTree(root);
    }    
    
    bool insert(int value) {
        return insert(root, value);
    }    
    
    bool search(int value) {
        Node * node = searchNode(root, value);
        return node;
    }
    
    // return true if the value exists and deleted, false if value does not exist
    bool deleteNode(int value) {
        Node *node = searchNode(root, value);
        if (!node) return false;
        Node *rightSmallest = findSmallestNode(node->right);
        if (rightSmallest) {
            rightSmallest->parent->left = rightSmallest->right;
            rightSmallest->right = node->right;
            rightSmallest->left = node->left;
            rightSmallest->parent = node->parent;
            node->parent->right = rightSmallest;
        } else {
            // node has not right children
            node->parent->right = node->left;
            node->left->parent = node->parent;
        }
        delete node;
        return true;
    }   
    
private:
    bool insert(Node * node, int value) {
        if(!node->left && node->value > value) {
            node->left = new Node(value);   
            node->left->parent = node;
            return true;
        } else if (!node->right && node->value < value) {
            node->right = new Node(value);   
            node->right->parent = node;
            return true;
        } else if (node->value < value) {
            return insert(node->right, value);   
        } else if (node->value > value) {
            return insert(node->left, value);   
        } else {
            return false; // value exists, insert fails
        }
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
    
    
    Node * searchNode(Node *node, int value) {
        if(!node) return nullptr;
        if(node->value == value) return node;
        if(node->value < value) {
            return searchNode(node->right, value);
        } else {
            return searchNode(node->left, value);
        }
    }
    
    Node *findSmallestNode(Node *node) {
        if (!node) return nullptr;
        if (!node->left) {
            return node;
        } else {
            findSmallestNode(node->left);
        }
    }
};






int main()
{
    
    BST bst(4);
    bst.insert(2);
    bst.insert(6);
    bst.insert(3);
    bst.insert(1);
    bst.insert(5);
    bst.insert(0);
    bst.insert(7);
    
    bst.printTree();
    bst.deleteTree();
    return 0;
}
