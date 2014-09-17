//
//  main.cpp
//  Construct_Binary_Tree_Pre_In_Order
//
//  Created by Shuai Wang on 9/16/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return build(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
    
    template <class InputIterator>
    TreeNode *build(InputIterator preStart, InputIterator preEnd, InputIterator inStart, InputIterator inEnd) {
        if (preStart == preEnd) {
            return nullptr;
        }
        
        if (inStart == inEnd) {
            return nullptr;
        }
        
        auto val = *preStart;
        auto root = new TreeNode (val);
        auto rootIn = find(inStart, inEnd, val);
        auto leftSize = distance(inStart, rootIn);
        
        root->left = build(next(preStart), next(preStart, leftSize + 1), inStart, rootIn);
        root->right = build(next(preStart, leftSize + 1), preEnd, next(rootIn), inEnd);
        return root;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

