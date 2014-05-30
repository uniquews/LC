//
//  main.cpp
//  ValidBinarySearchTree
//
//  Created by Shuai Wang on 5/8/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#inlcude "stack.h"


class TreeNode{
    
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    void diplayTree(TreeNode *root){
        stack *s = new stack ();
        if(root->left!=nullptr){
            
        }
    }
    
};

int main(int argc, const char * argv[])
{

    // insert code here...
    
    TreeNode *root = new TreeNode(5);
    TreeNode *left_1 = new TreeNode(3);
    TreeNode *right_1 = new TreeNode (6);
    
    root->left=left_1;
    root->right =right_1;
    
    
    
    std::cout << "Hello, World!\n";
    return 0;
}

