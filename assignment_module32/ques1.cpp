
#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
};

node* newNode(int data){
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return(Node);
}

int isSame(node* root1, node* root2){

    if (root1 == NULL && root2 == NULL)
        return 1;
    if (root1 != NULL && root2 != NULL){
        return(
                root1->data == root2->data &&
                isSame(root1->left, root2->left) &&
                isSame(root1->right, root2->right)
            );
        }
    return 0;
}

int main(){
    node *root1 = newNode(1);
    node *root2 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);
    if(isSame(root1, root2))
    cout << "Both tree are Same."<<endl;
    else
    cout << "Trees are not Same."<<endl;
    return 0;
}








// Given the roots of two binary trees, write a function named bool 
// isSame(Node* root1, Node* root2) which will take two roots and check if they are the same or not. 
// Two binary trees are considered the same if 
// they are structurally identical, and the nodes have the same value.