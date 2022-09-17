#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}

bool is_unival(Node* root){
    if (!root) {
         return true;
    }
    if (root->left != NULL
         && root->data != root->left->data)
         return false;

    if (root->right != NULL
        && root->data != root->right->data)
        return false;
    
    return is_unival(root->left)
        && is_unival(root->right);
}

int main(){
    Node* root = newNode(1);
    root->left = newNode(1);

    root->right = newNode(1);
    root->left->left = newNode(1);
    root->left->right = newNode(1);
    root->right->right = newNode(1);
    if (is_unival(root) == 1) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}