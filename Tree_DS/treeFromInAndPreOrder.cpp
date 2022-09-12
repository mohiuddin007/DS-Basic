#include<bits/stdc++.h>
using namespace std;

class treeNode {
public:
    int data;
    treeNode* leftChild;
    treeNode* rightChild;

    treeNode(int value){
        data = value;
        leftChild = NULL;
        rightChild = NULL;
    }
};

void printTree(treeNode* root, int level);
void spacePint(int level);

void inOrder(treeNode* root, string &chk){ //left root right
    if(root == NULL)
        return;

    inOrder(root->leftChild, chk);
    chk += to_string(root->data);
    inOrder(root->rightChild, chk);
}

void preOrderTrav(treeNode* root, string &chk){ // root left right 
    if(root == NULL)
        return;

    chk += to_string(root->data);
    preOrderTrav(root->leftChild, chk);
    preOrderTrav(root->rightChild, chk);
}

void postOrder(treeNode* root, string &chk){ //left right root
    if(root == NULL)
        return;

    postOrder(root->leftChild, chk);
    postOrder(root->rightChild, chk);
    chk += to_string(root->data);
}

void printTree(treeNode* root, int level){
    if(root == NULL){ //when the tree is empty
        return;
    } 
    if(root->leftChild == NULL && root->rightChild == NULL){ 
        cout<<root->data <<endl;
        return;
    } else {
        cout<<endl;
        spacePint(level);
        cout<< "Root: " << root->data <<endl;
    }

    if(root->leftChild != NULL){
        spacePint(level);
        cout<< "Left: ";
        printTree(root->leftChild, level+1);
    }

    if(root->rightChild != NULL){
        spacePint(level);
        cout<< "Right: ";
        printTree(root->rightChild, level+1);
    }
}

void spacePint(int level){
    for(int i=0; i<level; i++){
        cout<< "    ";
    }
}

int levelOrderTraversal(treeNode *root, string &chk, int k){
    if(root == NULL){
        return -1;
    }
    int level = 0;
    queue<treeNode*>q;
    q.push(root);
    q.push(NULL);
    int max = -1;

    while (!q.empty())
    {
        treeNode *chkNode = q.front();
        q.pop();
        if(chkNode != NULL){
            if(level == k){
                if(max < chkNode->data){                    
                    max=chkNode->data;
                }
            }
            cout<< chkNode->data <<" ";
            chk+=to_string(chkNode->data);
            if(chkNode->leftChild != NULL){
                q.push(chkNode->leftChild);
            } 

            if(chkNode->rightChild != NULL){
                q.push(chkNode->rightChild);

            } 
        } else {
            if(!q.empty()){
                q.push(NULL);
                level++;
            }
        }
    }
    return max;
}


int searchInOrder (int inOrder[], int current, int start, int end) {
    for (int i = start; i < end; i++)
    {   
        if(inOrder[i] == current){
            return i;
        }
    }
    return -1;
}

treeNode* buildTreePreIn(int preOrder[], int inOrder[], int start, int end){
    static int id = 0;
    int current = preOrder[id];
    id++;
    treeNode* newNode = new treeNode(current);
    if(start == end){
        return newNode;
    }
    int pos = searchInOrder(inOrder, current, start, end);
    
    newNode->leftChild = buildTreePreIn(preOrder, inOrder, start, pos-1);
    newNode->rightChild = buildTreePreIn(preOrder, inOrder, pos+1, end);
    return newNode;
}

int main(){
    int n;
    cin>>n;
    int preOrder[n], inOrder[n];
    
    for(int i=0; i<n; i++){
        cin>>preOrder[i];
    }

    for(int i=0; i<n; i++){
        cin>>inOrder[i];
    }

    treeNode* root = buildTreePreIn(preOrder, inOrder, 0, n-1);

    string chkPre = "";
    preOrderTrav(root, chkPre);
    cout<<chkPre<<endl<<endl;
    return 0;
}

/*
9
0 1 3 4 2 5 7 8 6 
3 1 4 0 7 5 8 3 6


9
0 1 2 
1 3 4
2 5 6
3 -1 -1
4 -1 -1
5 7 8
6 -1 -1
7 -1 -1
8 -1 -1

root: 0
left: 
    root: 1
    left: 3
    right: 4
right:
    root: 2
    left: 
        root: 5
        left: 7
        right: 8
    right: 6
*/