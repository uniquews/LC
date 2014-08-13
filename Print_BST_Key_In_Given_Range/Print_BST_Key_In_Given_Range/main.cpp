//
//  main.cpp
//  Print_BST_Key_In_Given_Range
//
//  Created by Shuai Wang on 8/13/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//


//TC: O(n)

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
    
    void printKey (TreeNode *root, vector<int> range) {
        
        if (root == nullptr) {
            return ;
        }
        
        printKeyInSubTree(root, range);
     
//        printKeyInSubTree(root, range, result);
//        sort(result.begin(), result.end());
//        adda(result);
        
  
    };
    
    
    void printKeyInSubTree(TreeNode *node, vector<int> range) {
        if (node == nullptr) {
            return;
        }
        
//        if (node->val > range[1]) {
//            printKeyInSubTree(node->left, range, result);
//            return;
//        }
//        
//        if (node->val >= range[0] && node->val <= range[1]) {
//            result.push_back(node->val);
//            cout<< node->val << endl;
//            vector<int> newRange1 = {range[0], node->val};
//            vector<int> newRange2 = {node->val, range[1]};
//            
//            printKeyInSubTree(node->left, newRange1, result);
//            printKeyInSubTree(node->right, newRange2, result);
//            return;
//        }
//        
//        if (node->val < range[0]) {
//            printKeyInSubTree(node->right, range, result);
//            return;
//        }
        
        if (node->val > range[0]) {
            printKeyInSubTree(node->left, range);
        }
        
        if (node->val >= range[0] && node->val <= range[1]) {
            cout << node->val<<" ";
        }
        
        if (node->val < range[1]) {
            printKeyInSubTree(node->right, range);
        }
        
        return;
    }
    

};

int main(int argc, const char * argv[])
{

    TreeNode *a = new TreeNode (20);
    TreeNode *b = new TreeNode (8);
    TreeNode *c = new TreeNode (22);
    TreeNode *d = new TreeNode (4);
    TreeNode *e = new TreeNode (12);
    
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    
    vector<int> range = {10, 22};
    
    Solution su;
    su.printKey(a, range);

    
//    vector<int> :: iterator it = result.begin();
//    for (; it != result.begin(); it++) {
//        cout << *it <<" ";
//    }
    
    cout << endl;
    
    return 0;
}

