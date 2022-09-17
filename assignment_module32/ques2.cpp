#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
    Node(int key)
    {
        this->key = key;
        this->left = NULL;
        this->right = NULL;
    }
};

bool printLevel(Node* root, int level)
{
    if (root == NULL) {
       return false;
    }
    if (level == 1){
        cout << root->key << " ";
        return true;
    }
    bool left = printLevel(root->left, level - 1);
    bool right = printLevel(root->right, level - 1);
    return left || right;
}

void level_Order(Node* root){
    int level = 1;

    while (printLevel(root, level)) {
        level++;
    }
}

int main(){
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->left->left = new Node(15);
    root->left->right = new Node(7);
    level_Order(root);
    return 0;
}