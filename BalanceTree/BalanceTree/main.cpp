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
        
        if(isBalanced(root, 1) == -1) {
            return false;
        } else {
            return true;
        }
    }
    
    int isBalanced(TreeNode *node, int depth) {
        if (node == nullptr) {
            return depth - 1;
        }
        
        int left = isBalanced(node->left, depth + 1);
        int right = isBalanced(node->right, depth + 1);
        
        if (left == -1) {
            return -1;
        }
        
        if (right == -1) {
            return -1;
        }
        
        if (abs(left - right) > 1) {
            return -1;
        }
        
        return max(left, right);
        
        
    }
    
};
int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

