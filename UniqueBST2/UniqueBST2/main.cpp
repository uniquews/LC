//
//  main.cpp
//  UniqueBST2
//
//  Created by Shuai Wang on 6/16/14.
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
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> result;
        generate(1, n, result);
        return result;
    }
    
    void generate (int start, int end, vector<TreeNode*> &result) {
        if (start > end) {
            result.push_back(NULL);
        } else {
            for (int i = start; i <= end; i++) {
                vector<TreeNode *> left;
                generate(start, i - 1, left);
                vector<TreeNode *> right;
                generate(i + 1, end, right);
                
                for (int l = 0; l < left.size(); l++) {
                    for (int r = 0; r < right.size(); r++) {
                        TreeNode *newRoot = new TreeNode(i);
                        newRoot->left = left[l];
                        newRoot->right = right[r];
                        result.push_back(newRoot);
                    }
                }
                
            }
            
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

