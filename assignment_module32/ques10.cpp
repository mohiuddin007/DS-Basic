#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};

void insert(TreeNode **root, int val){
    queue<TreeNode*> q;
    q.push(*root);
    while(q.size()){
        TreeNode *temp = q.front();
        q.pop();
        if(!temp->left){
            if(val != NULL)
                temp->left = new TreeNode(val);
            else
                temp->left = new TreeNode(0);
            return;
        }else{
            q.push(temp->left);
        }

        if(!temp->right){
            if(val!= NULL)
              temp->right = new TreeNode(val);
            else
              temp->right = new TreeNode(0);
            return;
        }else{
            q.push(temp->right);
        }
    }    
}

TreeNode *make_tree(vector<int> v){
    TreeNode *root = new TreeNode(v[0]);
    for(int i = 1; i<v.size(); i++){
         insert(&root, v[i]);
    }
    return root;
}

class Solution {
public:
    int second_minimum(TreeNode* root) {
        int min = (root && root->val != 0) ? root->val : -1;
        int nextMin = -1;
        TraverseNodes(root, min, nextMin);
        return nextMin;
    }
    void TraverseNodes(TreeNode* node, int min, int& nextMin) {
        if (!node || node->val == 0) {
            return;
        }
        if (node->val > min) {
            if (nextMin == -1 || node->val < nextMin) {
                nextMin = node->val;
            }
            TraverseNodes(node->left, min, nextMin);
            TraverseNodes(node->right, min, nextMin);
        }
};

int main(){
    Solution ob;
    vector<int> v = {2,2,5,NULL,NULL,5,7};
    TreeNode *root = make_tree(v);
    cout << (ob.second_minimum(root))
}