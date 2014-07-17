//
//  main.cpp
//  MergeSort
//
//  Created by Shuai Wang on 3/31/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
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
    void recoverTree(TreeNode *root) {
        pair<TreeNode *, TreeNode *> broken;
        TreeNode *cur = root;
        TreeNode *prev = nullptr;
        
        while(cur!=nullptr){
            if(cur->left == nullptr){
                detect(broken, prev, cur);
                prev = cur;
                cur = cur->right;
            }else{
                auto node = cur -> left; // node is specifically for thread pointer
                while(node->right!=nullptr && node->right !=cur){
                    node = node->right;
                }
                
                if(node->right == nullptr){
                    node->right = cur;
                    cur = cur->left;
                }else{
                    prev->right = nullptr;
                    detect(broken, prev, cur);
                    cur = cur->right;
                }
            }
        }
        
        swap(broken.first->val, broken.second->val);
    }
    
    
    void detect(pair<TreeNode *, TreeNode *>& broken, TreeNode *prev, TreeNode *cur){
        if(prev != nullptr && prev->val > cur->val){
            if(broken.first==nullptr){
                broken.first = prev;
            }
            // no else here!
            broken.second = cur;//will be change
        }
    }
};
int main(int argc, const char * argv[])
{
    
    // insert code here...
    TreeNode *a = new TreeNode (1);
    TreeNode *b = new TreeNode (2);
//        TreeNode *c = new TreeNode (3);
//        TreeNode *d = new TreeNode (4);
//        TreeNode *e = new TreeNode (5);
    
    b->right = a;
    
    Solution su;
    su.recoverTree(b);
    
    return 0;
}

