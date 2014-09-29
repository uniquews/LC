//
//  main.cpp
//  Convert Sorted Array to BST
//
//  Created by Shuai Wang on 9/29/14.
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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.size() == 0) {
            return nullptr;
        }
        
        return divide(0, num.size() - 1, num);
        
    }
    
    TreeNode *divide(int start, int end, vector<int> &num) {
        if (start > end) {
            return nullptr;
        } else if (start == end) {
            return new TreeNode(num[start]);
        } else {
            int mid = start + (end - start) / 2;
            TreeNode *cur = new TreeNode(num[mid]);
            TreeNode *leftNode = divide(start, mid - 1, num);
            TreeNode *rightNode = divide(mid + 1, end, num);
            cur->left = leftNode;
            cur->right = rightNode;
            
            return cur;
        }
    }
};

int main(int argc, const char * argv[])
{

    vector<int> num = {1, 3};
    Solution su;
    su.sortedArrayToBST(num);
    return 0;
}

