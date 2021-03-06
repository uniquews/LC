//
//  main.cpp
//  TreePostOrderTraver_Iterative
//
//  Created by Shuai Wang on 6/7/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

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
    vector<int> postorderTraversal(TreeNode *root) {
        if (root == nullptr) {
            return vector<int> {};
        }
        
        vector<int> result;
        stack<TreeNode *> stk;
        stk.push(root);
        TreeNode *last = root;
        while (stk.size() != 0) {
            TreeNode *current = stk.top();
            if ((current->left == nullptr && current->right == nullptr) || current->left == last || current->right == last) {
                result.push_back(current->val);
                stk.pop();
                last = current;
            } else {
                if (current->right != nullptr) {
                    stk.push(current);
                }
                
                if (current->left != nullptr) {
                    stk.push(current);
                }
            }
            
            
        }
        return result;
    }
    
    
};


class LevelOrderTraver{
public:
    vector<vector<int>> levelOrder(TreeNode *root){
        if(root==nullptr)
            return vector<vector<int>> {};
        

        vector<vector<int>> result;
        vector<int> layer;
        queue<TreeNode *> nodeQueue;
        nodeQueue.push(root);
        layer.push_back(root->val);
        result.push_back(layer);
        int numofNodeInLayer = 1;
        
        
        TreeNode *current;
        
        nodeQueue.push(root);
        while(nodeQueue.size()!=0){
            current  =  nodeQueue.front()->left;
            if(!current){
                nodeQueue.push(current);
                layer.push_back(current->val);
                numofNodeInLayer++;
            }
            
            current = nodeQueue.front()->right;
            if(!current){
                nodeQueue.push(current);
                layer.push_back(current->val);
                numofNodeInLayer++;
            }
            
            nodeQueue.pop();
            if(layer.size()==numofNodeInLayer){
                result.push_back(layer);
                layer.clear();
                numofNodeInLayer=0;
                
            }
        
        }
        
        
        
        return result;
    }
};

int main(int argc, const char * argv[])
{
    TreeNode *root = new TreeNode(1);
    Tree t(root);
    TreeNode *left1 = new TreeNode(2);
//    TreeNode *right1 = new TreeNode(3);
    root->left = left1;
//    root->right = right1;
    
//    TreeNode *left21 = new TreeNode (4);
//    TreeNode * right22 = new TreeNode (5);
//    
//    left1->left = left21;
//    left1->right = right22;
//    
//    TreeNode * left23 = new TreeNode(6);
//    TreeNode * right24 = new TreeNode(7);
//    right1->left = left23;
//    right1->right =right24;
    
    Solution s;
    vector<int> result = s.postorderTraversal(root);
//
    
    
    LevelOrderTraver tt;
    tt.levelOrder(root);
    
    cout <<endl;
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

