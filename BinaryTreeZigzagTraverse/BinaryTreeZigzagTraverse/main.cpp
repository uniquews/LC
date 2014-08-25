//
//  main.cpp
//  BinaryTreeZigzagTraverse
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        if(root==nullptr)
            return vector<vector<int>> {};
        
        vector<vector<int>> result;
        
        queue<TreeNode *> nodeQueue;
        vector<int> layer;
        vector<int>::iterator it;
        
        
        nodeQueue.push(root);
        
        int currentLayer = 1;
        int nextLayer = 0;
        bool leftToRight = true;
        
        
        while(nodeQueue.size()!=0){
            TreeNode *temp = nodeQueue.front();
            nodeQueue.pop();
            if(leftToRight==true){
                layer.push_back(temp->val);
            }else{
                it = layer.begin();
                layer.insert(it, temp->val);
            }
            
            if(temp->left){
                nodeQueue.push(temp->left);
                nextLayer++;
            }
            
            if(temp->right){
                nodeQueue.push(temp->right);
                nextLayer++;
            }
            
            if(layer.size()==currentLayer){
                currentLayer = nextLayer;
                nextLayer =0;
                result.push_back(layer);
                layer.clear();
                leftToRight=!leftToRight;
                
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
    
    
    Solution s;
    s.zigzagLevelOrder(root);
    std::cout << "Hello, World!\n";
    return 0;
}

