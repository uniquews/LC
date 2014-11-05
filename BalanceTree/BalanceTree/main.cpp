//
//  main.cpp
//  BalanceTree
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



class Tree{
public:
    TreeNode *root;
    Tree(TreeNode *t): root(t){};
    
};


class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        
        if (check(root) == -1) {
            return false;
        } else {
            return true;
        }
        
    }
    
    int check(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }
        
        if (node->left == nullptr && node->right == nullptr) {
            return 1;
        }
        
        int leftDepth = check(node->left);
        int rightDepth = check(node->right);
        if (leftDepth == -1 || rightDepth == -1 || abs(leftDepth - rightDepth) > 1) {
            return -1;
        }
        
        if (leftDepth == 0) {
            return rightDepth + 1;
        }
        
        if (rightDepth == 0) {
            return leftDepth + 1;
        }
        
        return max(leftDepth, rightDepth) + 1;
    }
};
int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

