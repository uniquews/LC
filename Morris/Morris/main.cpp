//
//  main.cpp
//  Morris
//  Using MOrris to implement in in order traverse
//  Created by Shuai Wang on 6/8/14.
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

class Solution{
public:
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
    std::cout << "Hello, World!\n";
    return 0;
}

