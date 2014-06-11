//
//  main.cpp
//  SymmetricTree_Iteration
//
//  Created by Shuai Wang on 6/11/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <stack>

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
    bool isSymmetric(TreeNode *root) {
        
        if(root==nullptr) return true;
        stack<TreeNode *> st;
        st.push(root->left);
        st.push(root->right);
        
        while(!st.empty()){
            TreeNode *q = st.top();
            st.pop();
            
            TreeNode *p = st.top();
            st.pop();
            
            if(!p && !q)  continue;
            if(!p || !q) return false;
            
            if(p->val != q->val) return false;
            else{
                st.push(p->left);
                st.push(q->right);
                
                st.push(p->right);
                st.push(q->left);
                
            }
        }
        return true;
        
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

