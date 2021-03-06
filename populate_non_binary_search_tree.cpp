
bool populateChildren(Node *node, int value) {
    if(!node->left) {
        node->left = new Node(value);
        return true;
    } else if (!node->right) {
        node->right = new Node(value);
        return true;
    }
    return false;
}

bool insertTree(vector <Node*> &vec, int value) {
    int size = vec.size();
    for(int i = 0; i < size; i++) {
        Node * node = vec[0];
        vec.erase(vec.begin());
        if(populateChildren(node, value)) {
            return true;
        } else {
            vec.push_back(node->left);
            vec.push_back(node->right);
        }
    }
    return false;
}

void insertTree(Node * node, int value) {
    vector<Node*> vec {node};
    int count = 0;
    while(!insertTree(vec, value)) {
        count ++;
        if(count == 10) break;
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
void printTreePreOrder(Node *root) {
    if (!root) return;
    cout << root->value << endl;
    printTreePreOrder(root->left);
    printTreePreOrder(root->right);
}
void printTreeInOrder(Node *root) {
    if (!root) return;
    printTreeInOrder(root->left);
    cout << root->value << endl;
    printTreeInOrder(root->right);
}
void printTreePostOrder(Node *root) {
    if (!root) return;
    printTreePostOrder(root->left);
    printTreePostOrder(root->right);
    cout << root->value << endl;
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
    printTree(root);
    return 0;
}
