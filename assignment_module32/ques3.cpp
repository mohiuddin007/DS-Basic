#include <bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;
};

void printGivenLevel(node* root, int level);
int height(node* node);
node* newNode(int data);

void Level_Order_Reverse(node* root){
    int h = height(root);
    int i;
    for (i=h; i>=1; i--)
    printGivenLevel(root, i);
}

void printGivenLevel(node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1){
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

int height(node* node){
    if (node == NULL)
        return 0;
    else{
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
            return(lheight + 1);
        else return(rheight + 1);
    }
}

node* newNode(int data){
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return(Node);
}

int main(){
    node *root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->left->left = newNode(15);
    root->left->right = newNode(7);
    Level_Order_Reverse(root);
    return 0;
}