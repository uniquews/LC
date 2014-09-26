//
//  main.cpp
//  Path_Sum2
//
//  Created by Shuai Wang on 7/21/14.
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        if (root == nullptr) {
            return vector<vector<int>> {};
        }
        vector<vector<int>> result;
        vector<int> eachResult;
        dfs(root, sum, eachResult, result);
        return result;
    }
    
    void dfs(TreeNode *node, int sum, vector<int> &eachResult, vector<vector<int>> &result) {
        
        if (node == nullptr) {
            return;
        }
        
        if (node->left == nullptr && node->right == nullptr) {
            if (node->val == sum) {
                eachResult.push_back(node->val);
                result.push_back(eachResult);
                eachResult.pop_back();
                return;
            }
            
            return;
        }
        
        eachResult.push_back(node->val);
        dfs(node->left, sum - node->val, eachResult, result);
        dfs(node->right, sum - node->val, eachResult, result);
        eachResult.pop_back();
        return;
        
    }
    
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

