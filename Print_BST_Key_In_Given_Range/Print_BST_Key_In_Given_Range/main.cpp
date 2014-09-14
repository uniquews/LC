//
//  main.cpp
//  Print_BST_Key_In_Given_Range
//
//  Created by Shuai Wang on 8/13/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//


//TC: O(n)

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
    int bstRangeSum(TreeNode *root, int start, int end) {
        vector<int> result;
        bstRange(root, start, end, result);
        int sum = 0;
        for (int i = 0; i < result.size(); i++) {
            sum += result[i];
        }
        
        return sum;
    }
    
    void bstRange(TreeNode *root, int start, int end, vector<int> &result) {
        if (root == nullptr) {
            return;
        }
        
        if (root -> val < start) {
            bstRange(root -> right, start, end, result);
        } else if (root -> val > end) {
            bstRange(root -> left, start, end, result);
        } else {
            result.push_back(root -> val);
            bstRange(root -> left, start, end, result);
            bstRange(root -> right, start, end, result);
        }
        
        return;
        
    }
    
};

int main(int argc, const char * argv[])
{

    TreeNode *a = new TreeNode (20);
    TreeNode *b = new TreeNode (8);
    TreeNode *c = new TreeNode (22);
    TreeNode *d = new TreeNode (4);
    TreeNode *e = new TreeNode (12);
    
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    
    vector<int> range = {10, 22};
    
    Solution su;
//    su.printKey(a, range);
    cout << su.bstRangeSum(a, 10, 20);

    
//    vector<int> :: iterator it = result.begin();
//    for (; it != result.begin(); it++) {
//        cout << *it <<" ";
//    }
    
    cout << endl;
    
    return 0;
}

