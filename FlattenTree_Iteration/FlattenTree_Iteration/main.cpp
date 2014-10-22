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


//class Solution {
//public:
//    void flatten(TreeNode *root) {
//        stack<TreeNode *> stk;
//        
//        if (root == nullptr) {
//            return;
//        }
//        
//        stk.push(root);
//        while (stk.size() != 0) {
//            TreeNode *tmp = stk.top();
//            stk.pop();
//            
//            if (tmp->right != nullptr) {
//                stk.push(tmp->right);
//            }
//            
//            if (tmp->left != nullptr) {
//                stk.push(tmp->left);
//            }
//            
//            tmp->left = nullptr;
//            if (stk.size() != 0) {
//                tmp->right = stk.top();
//            } else {
//                tmp->right = nullptr;
//            }
//            
//        }
//        
//        return;
//    }
//};


class Solution {
public:
    void flatten(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        TreeNode *last = nullptr;
        
        stack<TreeNode *> stk;
        stk.push(root);
        
        while (stk.size() != 0) {
            TreeNode *cur = stk.top();
            stk.pop();
          
            if (cur->right) {
                stk.push(cur->right);
            }
            
            if (cur->left) {
                stk.push(cur->left);
            }
            
            if (last == nullptr) {
                last = cur;
            } else {
                last->right = cur;
                last = last->right;
                
            }
            cur->left = nullptr;
            
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

