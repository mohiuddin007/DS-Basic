#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    
    Node(int data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
    }
};

void preorder(Node* root){
    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
    
}

void invert_tree(Node* root){
    if (root == nullptr) {
       return;
    }
    swap(root->left, root->right);
    invert_tree(root->left);
    invert_tree(root->right);
}

int main(){
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(9);
    invert_tree(root);
    preorder(root);
    return 0;
}