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
        int result = INT_MIN;
        
        _maxPathSum(root, result);
        return result;
    }
    
    int _maxPathSum(TreeNode *node, int &result){
        if(node == nullptr){
            return 0;
        }
        
        if(node->left == nullptr && node->right == nullptr){
            result = max(result, node->val);
            return node->val;
        }
        
        int sum = node->val;
        
        int leftSize = _maxPathSum(node->left, result);
        int rightSize = _maxPathSum(node->right, result);
        
        if(leftSize>0)
            sum+=leftSize;
        
        if(rightSize>0)
            sum+=rightSize;
        
        result = max(result, sum);
        
        return max(leftSize, rightSize)>0?node->val+max(leftSize,rightSize):node->val;  // for its parent, only one path of its child can be chosen.
        
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

