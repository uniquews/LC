//
//  main.cpp
//  ValidBST
//
//  Created by Shuai Wang on 12/15/14.
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
    bool isValidBST(TreeNode *root) {
        TreeNode *prev = nullptr;
        return valid(root, prev);
    }
    
    bool valid(TreeNode *root, TreeNode *&prev) {
        if (root == nullptr) {
            return true;
        }
        
        bool l = valid(root->left, prev);
        if (prev != nullptr && prev->val >= root->val) {
            return false;
        }
        
        prev = root;
        bool r = valid(root->right, prev);
        return l & r;
    }
    
    
};

int main(int argc, const char * argv[]) {
    TreeNode *root = new TreeNode(1);
    TreeNode *b = new TreeNode(1);
    root->left = b;
    Solution su;
    cout << su.isValidBST(root) << endl;
    return 0;
}
