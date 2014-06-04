//
//  main.cpp
//  TreeTraversePostOrder_Recursive
//
//  Created by Shuai Wang on 6/4/14.
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        if(root==nullptr) return result;
        post(root, result);
        return result;
    }
    
    
    void post(TreeNode *node, vector<int> &result){
        if(node==nullptr)
            return;
        if(node->left) post(node->left, result);
        if(node ->right) post(node->right, result);
        result.push_back(node->val);
        
        return;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

