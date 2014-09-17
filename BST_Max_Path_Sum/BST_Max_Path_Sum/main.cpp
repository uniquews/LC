//
//  main.cpp
//  BST_Max_Path_Sum
//
//  Created by Shuai Wang on 7/21/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>


class Solution {
public:
    int maxPathSum(TreeNode *root) {
        if (root == nullptr) {
            return INT_MIN;
        }
        
        int result = INT_MIN;
        divide(root, result);
        return result;
        
    }
    
    
    int divide(TreeNode *node, int &result) {
        if (node == nullptr) {
            return 0;
        } else if (node->left == nullptr && node->right == nullptr) {
            result = max(result, node->val);
            return node->val;
        } else {
            int sumAtNode = node->val;
            int leftVal = divide(node->left, result);
            int rightVal = divide(node->right, result);
            
            if (leftVal > 0) {
                sumAtNode += leftVal;
            }
            
            if (rightVal > 0) {
                sumAtNode += rightVal;
            }
            
            result = max(result, sumAtNode);
            
            return max(leftVal, rightVal) > 0 ? node->val + max(leftVal, rightVal) : node->val;
        }
    }
    
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

