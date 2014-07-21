//
//  main.cpp
//  Path_Sum
//
//  Created by Shuai Wang on 7/21/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        return _hasPathSum(root, sum);
    }
    
    bool _hasPathSum(TreeNode *node, int sum){
        if(node == nullptr) return false;
        
        if(node->left == nullptr && node->right == nullptr){
            if(node->val == sum) return true;
            else return false;
        }
        
        if(_hasPathSum(node->left, sum- node->val))
            return true;
        
        if(_hasPathSum(node->right, sum- node->val))
            return true;
        
        return false;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

