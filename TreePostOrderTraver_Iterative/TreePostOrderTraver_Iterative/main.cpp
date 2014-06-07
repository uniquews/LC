//
//  main.cpp
//  TreePostOrderTraver_Iterative
//
//  Created by Shuai Wang on 6/7/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        if(root==nullptr)
            return result;
        stack<TreeNode*> st;
        TreeNode *last =root;
        st.push(root);
        
        while(!st.empty()){
            TreeNode *current;
            current = st.top();
            if((current->left==nullptr && current->right==nullptr)||current->left==last ||current->right==last){
                result.push_back(current->val);
                st.pop();
                last=current;
            }else{
                if(current->right) st.push(current->right);
                if(current->left) st.push(current->left);
                
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

