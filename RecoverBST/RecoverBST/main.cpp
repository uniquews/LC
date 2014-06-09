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
        //firstly, implement the morris in-order traverse
        TreeNode *cur=root;
        TreeNode *prev = nullptr;
        TreeNode *parent=nullptr; // record the last tree node
        TreeNode *f1 =  nullptr;
        TreeNode *f2 = nullptr;
        bool found = false;
        
        while(cur!=nullptr){
            if(cur->left==nullptr){
                if(parent && parent->val > cur->val){
                    if(!found){
                        found = true;
                        f1 = parent; // if found is true, then the f1 will not be changed
                    }
                    f2 = cur; // make sure to store the first biggest and last small. If parent ->val > cur, f2 must be updated
                    
                }
                parent = cur;
                cur = cur->right;  //every time we change the cure, we need to update the parent node
            }else{
                // auto node = cur->left;
                prev = cur->left;
                while(prev->right!=nullptr && prev->right!= cur){
                    prev=prev->right;
                }
                
                if(prev->right==nullptr){
                    prev->right=cur;      // modify the threaded pointer
                    cur= cur->left;
                }else{
                    prev->right=nullptr;
                    if(parent->val > cur->val){
                        if(!found){
                            found = true;
                            f1 = parent;
                            
                        }
                        f2 = cur;
                        
                    }
                    parent = cur;
                    cur = cur->right;
                    
                }
                
            }
            
        }
        if(f1&&f2){
            swap(f1->val, f2->val);
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
        cout << *it;
    }
    cout << endl;
    
    

    return 0;
}

