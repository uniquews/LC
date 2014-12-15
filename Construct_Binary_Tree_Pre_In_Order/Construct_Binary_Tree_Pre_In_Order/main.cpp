//
//  main.cpp
//  Construct_Binary_Tree_Pre_In_Order
//
//  Created by Shuai Wang on 9/16/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//class Solution {
//public:
//    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
//        return build(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
//    }
//    
//    template <class InputIterator>
//    TreeNode *build(InputIterator preStart, InputIterator preEnd, InputIterator inStart, InputIterator inEnd) {
//        if (preStart == preEnd) {
//            return nullptr;
//        }
//        
//        if (inStart == inEnd) {
//            return nullptr;
//        }
//        
//        auto val = *preStart;
//        auto root = new TreeNode (val);
//        auto rootIn = find(inStart, inEnd, val);
//        auto leftSize = distance(inStart, rootIn);
//        
//        root->left = build(next(preStart), next(preStart, leftSize + 1), inStart, rootIn);
//        root->right = build(next(preStart, leftSize + 1), preEnd, next(rootIn), inEnd);
//        return root;
//    }
//};



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0 && inorder.size() == 0) {
            return nullptr;
        }
        
        return build(preorder, 0, (int)preorder.size() - 1, inorder, 0, (int)inorder.size() - 1);
    }
    
    TreeNode *build(vector<int> &preorder, int prestart, int preend, vector<int> &inorder, int instart, int inend) {
        if (prestart > preend || instart > inend) {
            return nullptr;
        }
        
        if (prestart == preend) {
            return new TreeNode(preorder[prestart]);
        }
        
        TreeNode *root = new TreeNode(preorder[prestart]);
        
        int rootIn = -1;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == preorder[prestart]) {
                rootIn = i;
                break;
            }
        }
        
        int leftSize = rootIn - instart;
        
        TreeNode *leftNode = build(preorder, prestart + 1, prestart + leftSize, inorder, instart, rootIn - 1);
        TreeNode *rightNode = build(preorder, prestart + leftSize + 1, preend, inorder, rootIn + 1, inend);
        
        root->left = leftNode;
        root->right = rightNode;
        return root;
    }
    
};

int main(int argc, const char * argv[])
{

    vector<int> preorder = {1,2};
    vector<int> inorder = {2,1};
    Solution su;
    su.buildTree(preorder, inorder);
    return 0;
}

