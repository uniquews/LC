//
//  main.cpp
//  TreePreOrderTraverse_Iteration
//
//  Created by Shuai Wang on 6/3/14.
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

class Solution{
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> st;
        
        if(root==nullptr){
            return result;
        }
        
        st.push(root);
        while(!st.empty()){
            TreeNode *temp = st.top();
            result.push_back(temp->val);
            st.pop();
            
            if(temp->right) st.push(temp->right);
            if(temp->left) st.push(temp->left);
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

