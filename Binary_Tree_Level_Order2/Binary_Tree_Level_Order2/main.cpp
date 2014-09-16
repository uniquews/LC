//
//  main.cpp
//  Binary_Tree_Level_Order2
//
//  Created by Shuai Wang on 7/15/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        if (root == nullptr) {
            return vector<vector<int>> {};
        }
        
        vector<vector<int>> result;
        vector<int> layer;
        vector<vector<int>> :: iterator it = result.begin();
        queue<TreeNode *> treeNodeList;
        treeNodeList.push(root);
        int nextLayer = 0;
        int currentLayer = 1;
        
        while (treeNodeList.size() != 0) {
            TreeNode *current = treeNodeList.front();
            treeNodeList.pop();
            layer.push_back(current->val);
            if (current->left != nullptr) {
                treeNodeList.push(current->left);
                nextLayer++;
            }
            
            if (current->right != nullptr) {
                treeNodeList.push(current->right);
                nextLayer++;
            }
            
            if (layer.size() == currentLayer) {
                result.insert(it, layer);
                currentLayer = nextLayer;
                nextLayer = 0;
                layer.clear();
                it = result.begin();  ////////////////////!!!!important!!!!
            }
        }
        
        return result;
    }
};

int main(int argc, const char * argv[])
{

    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    a->left = b;
    Solution su;
    su.levelOrderBottom(a);
    return 0;
}

