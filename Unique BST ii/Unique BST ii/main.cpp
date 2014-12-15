//
//  main.cpp
//  Unique BST ii
//
//  Created by Shuai Wang on 9/28/14.
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
 
//class Solution {
//public:
//    vector<TreeNode *> generateTrees(int n) {
//        if (n == 0) {
//            return vector<TreeNode *> {nullptr};
//        }
//        
//        vector<TreeNode *> result;
//        divide(1, n, result);
//        
//        return result;
//    }
//    
//    void divide(int start, int end, vector<TreeNode *> &result) {
//        if (start > end) {
//            result.push_back(NULL);
//            return;
//        } else {
//            for (int i = start; i <= end; i++) {
//                vector<TreeNode *> leftNode;
//                divide(start, i - 1, leftNode);
//                
//                vector<TreeNode *> rightNode;
//                divide(i + 1, end, rightNode);
//                
//                for (int m = 0; m < leftNode.size(); m++) {
//                    for (int k = 0; k < rightNode.size(); k++) {
//                        TreeNode *cur = new TreeNode(i);
//                        cur->left = leftNode[m];
//                        cur->right = rightNode[k];
//                        result.push_back(cur);
//                    }
//                }
//            }
//            
//        }
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
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) {
            return vector<TreeNode *> {nullptr};
        }
        
        vector<TreeNode *> result;
        divide(1, n, result);
        return result;
    }
    
    void divide(int start, int end, vector<TreeNode *> &result) {
        if (start > end) {
            result.push_back(nullptr);
            return;
        } else if (start == end) {
            TreeNode *cur = new TreeNode(start);
            result.push_back(cur);
            return;
        } else {
            for (int i = start; i <= end; i++) {
                vector<TreeNode *> leftSize;
                divide(start, i - 1, leftSize);
                
                vector<TreeNode *> rightSize;
                divide(i + 1, end, rightSize);
                
                for (int m = 0; m < leftSize.size(); m++) {
                    for (int n = 0; n < rightSize.size(); n++) {
                        TreeNode *cur = new TreeNode(i);
                        cur->left = leftSize[m];
                        cur->right = rightSize[n];
                        result.push_back(cur);
                    }
                }
            }
            return;
        }
    }
};

int main(int argc, const char * argv[])
{

    int n = 2;
    Solution su;
    su.generateTrees(n);
    return 0;
}

