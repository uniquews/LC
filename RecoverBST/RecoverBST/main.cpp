//
//  main.cpp
//  RecoverBST
//
//  Created by Shuai Wang on 6/9/14.
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



class Tree{
public:
    TreeNode *root;
    Tree(TreeNode *t): root(t){};
    
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
                    node->right = nullptr;
                    detect(broken, prev, cur);
                    
                    prev = cur;
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
    
    vector<int> inorderTraversal(TreeNode *root){
        vector<int>result;
        
        TreeNode *cur=root;
        TreeNode *prev = nullptr;
        
        while(cur!=nullptr){
            if(cur->left==nullptr){
                result.push_back(cur->val);  // the way to add left and right children
                cur = cur->right;
            }else{
                prev = cur->left;
                while(prev->right!=nullptr && prev->right!= cur){
                    prev=prev->right;
                }
                
                if(prev->right==nullptr){
                    prev->right=cur;      // modify the threaded pointer
                    cur= cur->left;
                }else{
                    prev->right=nullptr;
                    result.push_back(cur->val);  // return threaded pointer
                    cur = cur->right;
                }
                
            }
            
        }
        
        return result;
    }
    
};



int main(int argc, const char * argv[])
{

    // insert code here...
    TreeNode *root = new TreeNode(10);
    Tree t(root);
    TreeNode *a = new TreeNode(7);
    TreeNode *b = new TreeNode(3);
    TreeNode *c = new TreeNode(8);
    TreeNode *d = new TreeNode(13);
    TreeNode *e = new TreeNode(5);
    
//    TreeNode *root = new TreeNode(2);
//    Tree t(root);
//    TreeNode *a = new TreeNode(3);
//    TreeNode *b = new TreeNode(1);
//    
    root->left = a;
    root->right = d;
    a->left = b;
    a->right = c;
    d->left = e;
    
    Solution s;
    s.recoverTree(root);
    
    vector<int> r = s.inorderTraversal(root);
    
    vector<int>::iterator it = r.begin();
    for(; it!=r.end(); it++){
        cout << *it<<"--";
    }
    cout << endl;
    
    

    return 0;
}

