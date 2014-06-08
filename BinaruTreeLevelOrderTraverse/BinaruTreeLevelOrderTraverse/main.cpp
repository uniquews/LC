//
//  main.cpp
//  BinaruTreeLevelOrderTraverse
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

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        
        if(root==nullptr)
            return vector<vector<int>> {};
        vector<vector<int>> result;
        vector<int> layer;
        queue<TreeNode *> nodeQueue;
        nodeQueue.push(root);
        int nextLayer = 0;
        
        int currentLayer=1;
        
        TreeNode *current;
        
        
        while(nodeQueue.size()!=0){
            current  =  nodeQueue.front();
            // visited_inLayer++;
            layer.push_back(nodeQueue.front()->val);
            nodeQueue.pop();
            
            if(current->left){
                nodeQueue.push(current->left);
                
                nextLayer++;
            }
            
            
            if(current->right){
                nodeQueue.push(current->right);
                
                nextLayer++;
            }
            
            
            if(layer.size()==currentLayer){
                currentLayer = nextLayer;
                result.push_back(layer);
                layer.clear();
                nextLayer=0;
                
            }
            
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

