//
//  main.cpp
//  FlattenTree_Iteration
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
    void flatten(TreeNode *root) {
        
        if(root==nullptr) return;
        
        stack<TreeNode *> st;
        st.push(root);
        while(!st.empty()){
            TreeNode *p = st.top();
            st.pop();
            
            if(p->right)
                st.push(p->right);
            if(p->left)
                st.push(p->left);
            
            p->left = nullptr;
            if(!st.empty())
                p->right = st.top();
            
        }
        
        return;
        
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

