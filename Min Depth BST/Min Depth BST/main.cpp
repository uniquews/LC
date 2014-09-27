//
//  main.cpp
//  Min Depth BST
//
//  Created by Shuai Wang on 9/27/14.
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
    int minDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        
        if (left == 0) {
            return right + 1;
        }
        
        if (right == 0) {
            return left + 1;
        }
        
        return min(left, right) + 1;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

