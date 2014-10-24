//
//  main.cpp
//  Path Sum II
//
//  Created by Shuai Wang on 10/23/14.
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
            return vector<vector<int>> {{}};
        }
        
        vector<vector<int>> result;
        vector<int> eachResult;
        
        dfs(root, sum, result, eachResult);
        return result;
    }
    
    void dfs(TreeNode *root, int target, vector<vector<int>> &result, vector<int> &eachResult) {
        if (root == nullptr) {
            return;
        }
        
        if (root->left == nullptr && root->right == nullptr && root->val == target) {
            eachResult.push_back(root->val);
            result.push_back(eachResult);
            return;
        }
        
        eachResult.push_back(root->val);
        dfs(root->left, target - root->val, result, eachResult);
        dfs(root->right, target - root->val, result, eachResult);
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

