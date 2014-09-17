//
//  main.cpp
//  Construct_Binary_Tree_In_Post_Order
//
//  Created by Shuai Wang on 9/16/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>


class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return build(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
    
    template <class InputIterator>
    TreeNode* build(InputIterator inorderStart, InputIterator inorderEnd, InputIterator postStart, InputIterator postEnd){
        if(inorderStart == inorderEnd) return nullptr;
        if(postStart == postEnd) return nullptr;
        
        auto val = *prev(postEnd);
        auto root = new TreeNode (val);
        auto rootIn = find(inorderStart, inorderEnd, val);
        
        auto leftSize = distance(inorderStart, rootIn);
        
        root->left = build(inorderStart, rootIn, postStart, next(postStart, leftSize));
        
        root->right = build(next(rootIn), inorderEnd, next(postStart, leftSize), prev(postEnd));
        
        return root;
    }
    
    
};


int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

