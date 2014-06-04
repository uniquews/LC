//
//  main.cpp
//  TreePreOrderTraverse_Recursion
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        pre_recur(root, result);
        return result;
        
    }
    
    void pre_recur(TreeNode* root, vector<int> &res){
        if (!root){         //if null node, return
            return;
        }else{
            res.push_back(root->val); // traverse root child
            if (root->left){
                pre_recur(root->left,res); //traverse left child
            }
            if (root->right){
                pre_recur(root->right,res); //traverse right child
            }
        }
        return ;
    }
};

int main(int argc, const char * argv[])
{
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

