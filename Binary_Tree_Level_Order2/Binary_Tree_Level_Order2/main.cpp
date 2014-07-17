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
        if(root == nullptr) return vector<vector<int>>();
        list<vector<int>> resultT;
        vector<vector<int>> result;
        vector<int> layer;
        int currentLayer = 1;
        int nextLayer = 0;
        queue<TreeNode *> nodeQueue;
        
        nodeQueue.push(root);
        
        while(!nodeQueue.empty()){
            TreeNode *temp = nodeQueue.front();
            layer.push_back(temp->val);
            nodeQueue.pop();
            
            if(temp->left){
                nodeQueue.push(temp->left);
                nextLayer++;
            }
            
            if(temp->right){
                nodeQueue.push(temp->right);
                nextLayer++;
            }
            
            if(layer.size()  == currentLayer){
                resultT.push_back(layer);
                currentLayer = nextLayer;
                layer.clear();
                nextLayer = 0;
                
            }
        }
        
        
        while(!resultT.empty()){
            result.push_back(resultT.back());
            resultT.pop_back();
        }
        
        return result;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

