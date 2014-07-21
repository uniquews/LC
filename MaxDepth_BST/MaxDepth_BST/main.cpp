//
//  main.cpp
//  MaxDepth_BST
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
    int maxDepth(TreeNode *root) {
        if(root==nullptr)    return 0;
        return _maxDepth(root, 1);
    }
    
    int _maxDepth(TreeNode *node, int cur){
        if(node== nullptr) return --cur;
        
        int left = _maxDepth(node->left, cur+1);
        int right = _maxDepth(node->right, cur+1);
        
        return max(left, right);
        
    }
    
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

