//
//  main.cpp
//  PopulatingRightNode1
//
//  Created by Shuai Wang on 6/11/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct TreeLinkNode {
      int val;
      TreeLinkNode *left, *right, *next;
      TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
    
};

//class Solution {
//public:
//    void connect(TreeLinkNode *root) {
//        if(root==nullptr) return;
//        vector<TreeLinkNode *> layer;
//        queue<TreeLinkNode *> nodeQueue;
//        
//        int currentLayer = 1;
//        int nextLayer = 0;
//        
//        nodeQueue.push(root);
//        
//        while(!nodeQueue.empty()){
//            TreeLinkNode *p = nodeQueue.front();
//            nodeQueue.pop();
//            layer.push_back(p);
//            
//            if(p->left){
//                nodeQueue.push(p->left);
//                nextLayer++;
//                
//            }
//            
//            if(p->right){
//                nodeQueue.push(p->right);
//                nextLayer++;
//            }
//            
//            if(layer.size()==currentLayer){
//                for(int i = 0; i<layer.size(); i++){
//                    if(i==layer.size()-1){
//                        layer[i]->next = NULL;
//                    }else{
//                        layer[i]->next = layer[i+1];
//                    }
//                }
//                
//                currentLayer = nextLayer;
//                nextLayer = 0;
//                layer.clear();
//            }
//            
//        }
//        
//        return;
//    }
//};


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root==nullptr) return;
        vector<TreeLinkNode *> layer;
        queue<TreeLinkNode *> nodeQueue;
        
        int currentLayer = 1;
        int nextLayer = 0;
        
        nodeQueue.push(root);
        
        TreeLinkNode dummy(-1);
        TreeLinkNode *prev = &dummy;
        
        while(!nodeQueue.empty()){
            TreeLinkNode *p = nodeQueue.front();
            nodeQueue.pop();
            currentLayer--;
            prev->next = p;
            prev = prev->next;
            
            if(p->left){
                nodeQueue.push(p->left);
                nextLayer++;
                
            }
            
            if(p->right){
                nodeQueue.push(p->right);
                nextLayer++;
            }
            
            if(currentLayer == 0){
                prev->next = nullptr;
                prev = &dummy;
                currentLayer = nextLayer;
                nextLayer = 0;
            }
            
        }
        
        return;
    }
};


int main(int argc, const char * argv[])
{

    
    TreeLinkNode *a = new TreeLinkNode(1);
    TreeLinkNode *b = new  TreeLinkNode(2);
    TreeLinkNode *c = new TreeLinkNode(3);
    
    a->left = b;
    a->right = c;
    
    Solution s;
    s.connect(a);
    
    

    
    // insert code here...
//    std::cout << "Hello, World!\n";
    return 0;
}

