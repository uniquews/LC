//
//  main.cpp
//  TreeTraverseInorder_Iterative
//
//  Created by Shuai Wang on 6/4/14.
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> st;
        if(root==nullptr){
            return result;
        }
        
        TreeNode *current = root;
        // st.push(current);
        
        while(st.size()>0 || current!=nullptr){
            if(current){
                st.push(current);
                current = current->left;
            }else {
                current = st.top();
                result.push_back(current->val);
                st.pop();
                current = current->right;
                
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

