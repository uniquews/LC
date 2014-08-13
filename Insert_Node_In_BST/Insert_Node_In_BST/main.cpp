//
//  main.cpp
//  Insert_Node_In_BST
//
//  Created by Shuai Wang on 8/13/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

public:
    
    TreeNode * insertNodeBST(TreeNode *root, int nodeVal) {
        if (root == nullptr) {
            TreeNode *newRoot = new TreeNode (nodeVal);
            return newRoot;
        }
        
        TreeNode *prev = root;
        
        
        if (root->val <= nodeVal) {
            bool left = false;
            insertNode(root->right, prev, left, nodeVal);
        } else {
            bool left = true;
            insertNode(root->left, prev, left, nodeVal);
        }
        
        return root;
    }
    
    void insertNode(TreeNode *node, TreeNode *prev, bool left, int nodeVal) {
        if (node == nullptr) {
            TreeNode *newNode = new TreeNode (nodeVal);
            if (left == true) {
                prev->left = newNode;
                return;
            } else {
                prev->right = newNode;
                return;
            }
        }
        
        prev = node;
        
        if (node->val < nodeVal) {
            left = false;
            return insertNode(node->right, prev, left, nodeVal);
        } else {
            left = true;
            return insertNode(node->left, prev, left, nodeVal);
        }
    }
    
    
    vector<int> inorderTraversal(TreeNode *root){
        vector<int>result;
        
        TreeNode *cur=root;
        TreeNode *prev = nullptr;
        
        while(cur!=nullptr){
            if(cur->left==nullptr){
                result.push_back(cur->val);  // the way to add left and right children
                cur = cur->right;
            }else{
                prev = cur->left;
                while(prev->right!=nullptr && prev->right!= cur){
                    prev=prev->right;
                }
                
                if(prev->right==nullptr){
                    prev->right=cur;      // modify the threaded pointer
                    cur= cur->left;
                }else{
                    prev->right=nullptr;
                    result.push_back(cur->val);  // return threaded pointer
                    cur = cur->right;
                }
                
            }
            
        }
        
        return result;
    }
    
};

int main(int argc, const char * argv[])
{

    TreeNode *a = new TreeNode (10);
    TreeNode *b = new TreeNode (5);
    TreeNode *c = new TreeNode (12);
    
    a->left = b;
    a->right = c;
    
   
    
    Solution su;
    su.insertNodeBST(a, 9);
    
    vector<int> result = su.inorderTraversal(a);
    vector<int> :: iterator it = result.begin();
    for (; it != result.end(); it++) {
        cout << *it;
    }
    
    cout << endl;
    
    
    
    return 0;
}

