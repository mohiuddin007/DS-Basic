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

int main(){
    treeNode* n1 = new treeNode(0);
    treeNode* n2 = new treeNode(1);

    n1->leftChild=n2;
    
    return 0;
}

/*
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