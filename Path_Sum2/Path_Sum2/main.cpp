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
        vector<vector<int>> result;
        vector<int> level;
        _pathSum(root, sum, result, level);
        return result;
    }
    
    void _pathSum(TreeNode *node, int sum, vector<vector<int>> &result, vector<int> level){
        if(node == nullptr){
            return;
        }
        
        level.push_back(node->val);
        if(node ->left == nullptr && node->right == nullptr && node->val == sum){
            result.push_back(level);
            level.pop_back();
            return;
        }
        
        _pathSum(node->left, sum - node->val, result, level);
        _pathSum(node->right, sum - node->val, result, level);
        
        level.pop_back();
        
        return;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

