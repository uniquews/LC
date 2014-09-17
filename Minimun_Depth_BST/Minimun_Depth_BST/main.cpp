//
//  main.cpp
//  Minimun_Depth_BST
//
//  Created by Shuai Wang on 7/21/14.
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
        } else {
            return divide(root, 1);
        }
    }
    
    int divide(TreeNode *node, int depth) {
        if (node == nullptr) {
            return depth - 1;
        } else if (node->left == nullptr && node->right == nullptr) {
            return depth;
        } else {
            int leftDepth = divide(node->left, depth + 1);
            int rightDepth = divide(node->right, depth + 1);
            
            if (leftDepth == depth) {
                return rightDepth;
            }
            
            if (rightDepth == depth) {
                return leftDepth;
            }
            
            return min(leftDepth, rightDepth);
        }
    }
};
int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

