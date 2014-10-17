//
//  main.cpp
//  FlattenTree_Recursion
//
//  Created by Shuai Wang on 6/11/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        
        TreeNode *leftNode = root->left;
        TreeNode *rightNode = root->right;
        
        flatten(leftNode);
        flatten(rightNode);
        
        if (leftNode == nullptr && rightNode == nullptr) {
            return;
        }
        root->left = nullptr;
        
        TreeNode *tmp = leftNode;
        if (tmp == nullptr) {
            return;
        }
        
        while (tmp->right != nullptr) {
            tmp = tmp->right;
        }
        
        tmp->right = rightNode;
        root->right = leftNode;
        return;
    }
};



int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

