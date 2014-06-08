//
//  main.cpp
//  BinaryTreeLevelOrderTraverse
//
//  Created by Shuai Wang on 6/8/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
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

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> result;
        vector<int> layer;
        queue<TreeNode *> treeNodeList;
        
        if(root==nullptr)
            return vector<vector<int>> {};
        
        int nextLayer = 0;
        int currentLayer = 1;
        
        vector<vector<int>>::iterator it = result.begin();
        // layer.push_back(root->val);
        // result.insert(it, layer);
        
        // layer.clear();
        
        treeNodeList.push(root);
        
        while(treeNodeList.size()!=0){
            TreeNode *temp = treeNodeList.front();
            treeNodeList.pop();
            layer.push_back(temp->val);
            
            if(temp->left!=nullptr){
                treeNodeList.push(temp->left);
                nextLayer++;
            }
            
            if(temp->right!=nullptr){
                treeNodeList.push(temp->right);
                nextLayer++;
            }
            
            if(layer.size()==currentLayer){
                result.insert(it, layer);
                currentLayer  =nextLayer;
                layer.clear();
                nextLayer=0;
//                it=result.begin(); // important!
            }
        }
        return result;
    }
};


int main(int argc, const char * argv[])
{

    // insert code here...
    
    TreeNode *root = new TreeNode(1);
    Tree t(root);
    TreeNode *left1 = new TreeNode(2);
//    TreeNode *right1 = new TreeNode(3);
    root->left = left1;
//    root->right = right1;
//    
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
    s.levelOrderBottom(root);
    std::cout << "Hello, World!\n";
    return 0;
}

