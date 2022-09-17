#include <bits/stdc++.h>
#include <stack>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
};

void zizag_order(struct Node* root){
    if (!root)
        return;
    
    stack<struct Node*> currentlevel;
    
    stack<struct Node*> nextlevel;
    currentlevel.push(root);

    bool lefttoright = true;
    while (!currentlevel.empty()) {
        
        struct Node* temp = currentlevel.top();
        currentlevel.pop();
        if (temp) {
            cout << temp->data << " ";
            if (lefttoright) {
                if (temp->left)
                        nextlevel.push(temp->left);
                 if (temp->right)
                        nextlevel.push(temp->right);
            }
            else {
                if (temp->right)
                    nextlevel.push(temp->right);
                if (temp->left)
                    nextlevel.push(temp->left);
            }
        }
        if (currentlevel.empty()) {
            lefttoright = !lefttoright;
            swap(currentlevel, nextlevel);
        }
    }
}

struct Node* newNode(int data)
{
    struct Node* node = new struct Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

int main(){
    struct Node* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->left->left = newNode(15);
    root->left->right = newNode(7);
    zizag_order(root);
    return 0;
}