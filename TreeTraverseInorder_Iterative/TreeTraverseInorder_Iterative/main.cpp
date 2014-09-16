//
//  main.cpp
//  TreeTraverseInorder_Iterative
//
//  Created by Shuai Wang on 6/4/14.
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
    vector<int> inorderTraversal(TreeNode *root) {
        if (root == nullptr) {
            return vector<int> {};
        }
        
        vector<int> result;
        stack<TreeNode *> stk;
        TreeNode *current = root;
        
        while(stk.size() != 0 || current != nullptr) {
            if (current) {
                stk.push(current);
                current = current->left;
            } else {
                current = stk.top();
                result.push_back(current->val);
                stk.pop();
                current = current->right;
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

