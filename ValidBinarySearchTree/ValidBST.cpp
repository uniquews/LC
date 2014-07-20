//
//  ValidBST.cpp
//  ValidBinarySearchTree
//
//  Created by Shuai Wang on 7/20/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return isValidBST(root, INT_MIN, INT_MAX);
    }
    
    
    bool isValidBST(TreeNode *root, int lower, int higher){
        if(root == nullptr)
            return true;
        
        return root->val >lower && root->val < higher &&
        isValidBST(root->left, lower, root->val) &&
        isValidBST(root->right, root->val, higher);
    }
};

int main(int argc, const char * argv[])
{
    
    Solution su;
    TreeNode *a = new TreeNode(10);
    TreeNode *b = new TreeNode(5);
    TreeNode *c = new TreeNode(15);
    
    
    TreeNode *d = new TreeNode(6);
    TreeNode *e = new TreeNode(20);
    
    a->left = b;
    a->right = c;
    c->left = d;
    c->right = e;
    

    
    su.isValidBST(a);
    return 0;
}