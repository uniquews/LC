//
//  main.cpp
//  BalanceTree
//
//  Created by Shuai Wang on 6/11/14.
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



class Tree{
public:
    TreeNode *root;
    Tree(TreeNode *t): root(t){};
    
};


class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if(root==nullptr) return true;
        int value = valid(root);
        if(value == -1) return false;
        return true;
    }
    
    int valid(TreeNode *node){
        if(node==nullptr) return 0;
        // else{
        int left = valid(node->left);
        if(left == -1) return -1;
        int right = valid(node->right);
        if(right== -1) return -1;
        if(abs(left-right)>1) return -1;
        
        return left>right?left+1:right+1;
        
        // }
        
        
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

