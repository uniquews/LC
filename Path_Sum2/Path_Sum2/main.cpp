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
        if (root == nullptr) {
            return result;
        }
        
        divide(root, sum, result, level);
        return result;
    }
    
    void divide(TreeNode *root, int sum, vector<vector<int>> &result, vector<int> &level) {
        if (root == nullptr) {
            return;
        } else if (root->left == nullptr && root->right == nullptr) {
            if (root->val == sum) {
                level.push_back(root->val);
                result.push_back(level);
                level.pop_back();
                return;
            } else {
                return;
            }
            
        } else {
            level.push_back(root->val);
            divide(root->left, sum - root->val, result, level);
            divide(root->right, sum - root->val, result, level);
            level.pop_back();
        }
        
        return;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

