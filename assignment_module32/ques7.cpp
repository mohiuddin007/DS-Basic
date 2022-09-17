#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    struct Node *left, *right;
};

int traverse(Node* root, int* title){
    if (!root)
    return 0;
    int left = traverse(root->left, title);
    int right = traverse(root->right, title);
    *title += abs(left - right);
    return left + right + root->val;
}

int findTilt(Node* root){
    int tilt = 0;
    traverse(root, &tilt);
    return tilt;
}

Node* newNode(int data){
    Node* temp = new Node;
    temp->val = data;
    temp->left = temp->right = NULL;
    return temp;
}

int main(){
    Node* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    cout << findTilt(root);
    return 0;
}