//
//  main.cpp
//  BST Max Path Sum
//
//  Created by Shuai Wang on 10/24/14.
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
    int maxPathSum(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        
        int result = INT_MIN;
        pathSum(root, result);
        return result;
    }
    
    int pathSum(TreeNode *root, int &result) {
        if (root == nullptr) {
            return 0;
        }
        
        int sum = root->val;
        int leftSum = pathSum(root->left, result);
        int rightSum = pathSum(root->right, result);
        
        if (leftSum > 0) {
            sum += leftSum;
        }
        
        if (rightSum > 0) {
            sum += rightSum;
        }
        
        result = max(result, sum);
        
        if (max(leftSum, rightSum) > 0) {
            return max(leftSum, rightSum) + root->val;
        } else {
            return root->val;
        }
        
    }
};

int main(int argc, const char * argv[])
{

    TreeNode *a = new TreeNode (1);
    TreeNode *b = new TreeNode (2);
    TreeNode *c = new TreeNode (3);
    
    a->left = b;
    a->right = c;
    
    Solution su;
    cout << su.maxPathSum(a) << endl;
    return 0;
}

