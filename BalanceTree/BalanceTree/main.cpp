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
        if(root == nullptr) return true;
        
        if(valid(root) == -1)
            return false;
        else
            return true;
        
    }
    
    int valid (TreeNode * p){
        if(p == nullptr) return 0;
        int left = valid(p->left);
        if(left == -1) return -1;
        int right = valid(p->right);
        if(right == -1) return -1;
        
        if(abs(left - right) >1) return -1;
        
//        if(left == right) return 0; cannot add this, because as long as you explore a this level, at least you should add one on its children node. Here, since the children level are already balanced, this return number is for parent node to compare with its sibling. Thus we can easliy add 1 to its left or right children.
        
        return left>right?left+1:right+1;
    }
    
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

