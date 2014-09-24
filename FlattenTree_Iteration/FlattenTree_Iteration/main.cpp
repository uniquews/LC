//
//  main.cpp
//  FlattenTree_Iteration
//
//  Created by Shuai Wang on 6/11/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <stack>

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
//        stack<TreeNode *> stk;
//        
//        if (root == nullptr) {
//            return;
//        }
//        
//        stk.push(root);
//        while (stk.size() != 0) {
//            TreeNode *tmp = stk.top();
//            stk.pop();
//            
//            if (tmp->right != nullptr) {
//                stk.push(tmp->right);
//            }
//            
//            if (tmp->left != nullptr) {
//                stk.push(tmp->left);
//            }
//            
//            tmp->left = nullptr;
//            if (stk.size() != 0) {
//                tmp->right = stk.top();
//            } else {
//                tmp->right = nullptr;
//            }
//            
//        }
//        
//        return;
//    }
//};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

