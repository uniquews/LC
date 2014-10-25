//
//  main.cpp
//  Sum Root to Leaf Number
//
//  Created by Shuai Wang on 9/21/14.
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
    int sumNumbers(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        
        int result = 0;
        return divide(root, result);
        
    }
    
    int divide(TreeNode *node, int result) {
        if (node == nullptr) {
            return 0;
        }
        
        if (node->left == nullptr && node->right == nullptr) {
            return result * 10 + node->val;
        }
        
        return divide(node->left, result * 10 + node->val) + divide(node->right, result * 10 + node->val);
        
    }
    
    
};


int main(int argc, const char * argv[])
{

    TreeNode *a = new TreeNode (1);
    TreeNode *b = new TreeNode (2);
    TreeNode *c = new TreeNode (3);
    TreeNode *d = new TreeNode (4);
    TreeNode *e = new TreeNode (5);
    TreeNode *f = new TreeNode (6);
    TreeNode *g = new TreeNode (7);
    
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    
    
    Solution su;
    cout << su.sumNumbers(a) << endl;
    return 0;
}

