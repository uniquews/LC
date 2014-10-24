//
//  main.cpp
//  FlattenTree_Iteration
//
//  Created by Shuai Wang on 6/11/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Tree{
public:
    TreeNode *root;
    Tree(TreeNode *t): root(t){};
    
};


class Solution {
public:
    void flatten(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        
        
        stack<TreeNode *> stk;
        stk.push(root);
        
        while (stk.size() != 0) {
            TreeNode *cur = stk.top();
            stk.pop();
            if (cur->right != nullptr) {
                stk.push(cur->right);
            }
            
            if (cur->left != nullptr) {
                stk.push(cur->left);
            }
            
            cur->left = nullptr;
            if (stk.size() != 0) {
                cur->right = stk.top();
            } else {
                cur->right = nullptr;
            }
            
        }
        
        return;
    }
    
    
};



int main(int argc, const char * argv[])
{

    TreeNode *a = new TreeNode (1);
    TreeNode *b = new TreeNode (2);
    TreeNode *c = new TreeNode (3);
    a->left = b;
    a->right = c;
    
    Solution su;
    su.flatten(a);
    while (a != nullptr) {
        cout << a->val << endl;
        a = a->right;
    }
    return 0;
}

