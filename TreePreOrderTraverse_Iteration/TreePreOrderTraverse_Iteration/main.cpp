//
//  main.cpp
//  TreePreOrderTraverse_Iteration
//
//  Created by Shuai Wang on 6/3/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode *> stk;
        vector<int> result;
        if (root == nullptr) {
            return vector<int> {};
        }
        
        stk.push(root);
        while (stk.size() != 0) {
            TreeNode *tmp = stk.top();
            result.push_back(tmp->val);
            stk.pop();
            
            if (tmp->right != nullptr) {
                stk.push(tmp->right);
            }
            
            if (tmp->left != nullptr) {
                stk.push(tmp->left);
            }
        }
        
        return result;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

