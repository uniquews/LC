//
//  main.cpp
//  Construct_Binary_Tree_In_Post_Order
//
//  Created by Shuai Wang on 9/16/14.
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
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() == 0 && postorder.size() == 0) {
            return nullptr;
        }
        
        return convert(inorder, 0, (int)inorder.size() - 1, postorder, 0, (int)postorder.size() - 1);
    }
    
    TreeNode * convert(vector<int> &inorder, int instart, int inend, vector<int> &postorder, int poststart, int postend) {
        // [2,1] [2,1] 右子树越界。
        if (instart > inend || poststart > postend) {
            return nullptr;
        }
        
        if (instart == inend) {
            return new TreeNode(inorder[instart]);
        }
        
        TreeNode *cur = new TreeNode(postorder[postend]);
        int rootIn = -1;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == postorder[postend]) {
                rootIn =  i;
                break;
            }
        }
        
        int leftSize = rootIn - instart;
        TreeNode *leftNode = convert(inorder, instart, rootIn - 1, postorder, poststart, poststart + leftSize - 1);
        TreeNode *rightNode = convert(inorder, rootIn + 1, inend, postorder, poststart + leftSize, postend - 1);
        cur->left = leftNode;
        cur->right = rightNode;
        return cur;
        
    }
};


int main(int argc, const char * argv[])
{

    vector<int> inorder = {2,1};
    vector<int> postorder = {2,1};
    Solution su;
    TreeNode *result = su.buildTree(inorder, postorder);
    cout << result->val;
    return 0;
}

