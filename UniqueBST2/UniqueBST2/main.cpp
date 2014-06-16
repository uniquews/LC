//
//  main.cpp
//  UniqueBST2
//
//  Created by Shuai Wang on 6/16/14.
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
    
    void dfs(int start, int end, vector<TreeNode *> &res){
        if(start>end){
            res.push_back(NULL);
        }else{
            for(int i=start; i<=end; i++){
                vector<TreeNode *> lefts;
                dfs(start, i-1, lefts);
                vector<TreeNode *> rights;
                dfs(i+1, end, rights);
                
                for(int li=0; li<lefts.size(); li++){
                    for(int ri=0; ri<rights.size(); ri++){
                        TreeNode *node = new TreeNode(i); // root node (substree)
                        node->left = lefts[li];
                        node->right = rights[ri];
                        res.push_back(node);
                    }
                }
            }
        }
    }
    vector<TreeNode *> generateTrees(int n) {
        vector <TreeNode *> res;
        dfs(1, n, res);
        return res;
    }
    
    
    
    
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

