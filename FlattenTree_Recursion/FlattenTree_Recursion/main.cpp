//
//  main.cpp
//  FlattenTree_Recursion
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


//class Solution {
//public:
//    void flatten(TreeNode *root) {
//        if(root==nullptr)
//            return;
//        
//        //if(root->left==nullptr) return;  // cannot put this here
//        
//        flatten(root->left);
//        flatten(root->right);
//        
//        if(root->left==nullptr) return;// you must put this here after flatten the left and right sub tree.
//        // the reason is that: is we put root->left == nullptr ahead, when input is  {1,#,2,3}, it will irectly return and not won't check the root->right sub tree.
//        
//        
//        TreeNode *p = root->left;
//        while(p->right) p = p->right;
//        
//        p->right = root->right;
//        root->right = root->left;
//        root->left = nullptr;
//        
//        return;
//    }
//};

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        dfs(root);
        return;
    }
    
    TreeNode *dfs(TreeNode *node) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->left == nullptr && node->right == nullptr) {
            return node;
        }
        
        TreeNode *leftNode = dfs(node->left);
        
        TreeNode *rightNode = dfs(node->right);
        TreeNode *tmp = leftNode;
        while (tmp != nullptr && tmp->right != nullptr) {
            tmp = tmp->right;
        }
        
        if (tmp != nullptr) {
            tmp->right = rightNode;
            node->right = leftNode;
        }
        
        node->left = nullptr;
        
        return node;
        
    }
    
};



int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

