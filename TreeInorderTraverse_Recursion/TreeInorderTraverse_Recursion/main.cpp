//
//  main.cpp
//  TreeInorderTraverse_Recursion
//
//  Created by Shuai Wang on 6/3/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        inorder(root, result);
        
        return result;
    }
    
    
    
    void inorder(TreeNode *root, vector<int> &result){
        if(root==nullptr)
            return;
        if(root->left) inorder(root->left, result);
        result.push_back(root->val);
        if(root->right) inorder(root->right, result);
        
        return;
    }
};


int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

