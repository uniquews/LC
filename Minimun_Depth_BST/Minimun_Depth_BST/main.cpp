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
        if(root == nullptr) return 0;
        
        return _minDepth(root, 1);
    }
    
    int _minDepth(TreeNode * node, int cur){
        if(node == nullptr)  return --cur;
        
        int leftDepth = _minDepth(node->left, cur+1);
        int rightDepth = _minDepth(node->right, cur+1);
        
        if(leftDepth == cur) return rightDepth; // if one child is null, we have to get the longest and worest (another child)
        if(rightDepth == cur) return leftDepth; // the same;
        
        return min(leftDepth, rightDepth);
        
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

