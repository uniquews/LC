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
        if (root == nullptr){
            return 0;
        }else{
            return _minDepth(root, 1);
        }
    }
    
    
    int _minDepth(TreeNode *node, int depth){
        if(node == nullptr){
            return depth - 1;
        }else{
            int left = _minDepth(node -> left, depth + 1);
            int right = _minDepth(node ->right, depth + 1);
            
            if (left == depth){ // left is null, you have to return the right
                return right;
            }
            
            if (right == depth){
                return left;
            }
            
            return min(left, right);
            
        }
    }
    
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

