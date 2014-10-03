//
//  main.cpp
//  Contruct Max Tree
//
//  Created by Shuai Wang on 10/3/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *parent;
    bool isLeft;
    bool isRIght;
    TreeNode *leftChild;
    TreeNode *rightChild;
    
    TreeNode (int val) {
        this->val = val;
    }

};



class Solution {

public:
    unordered_map<int , int> constructMaxTree(vector<int> &num) {
        vector<int> leftMax(num.size());
        vector<int> rightMax(num.size());
        
        stack<int> stk;
        for (int i = 0; i <= num.size(); i++) {
            int cur = i == num.size() ? INT_MAX : num[i];
            while (stk.size() != 0 && cur > num[stk.top()]) {
                int tmp = stk.top();
                stk.pop();
                if (i == num.size()) {
                    rightMax[tmp] = INT_MAX;
                } else {
                    rightMax[tmp] = i;
                }
                
            }
            
            stk.push(i);
        }
        
        while (stk.size() != 0) {
            stk.pop();
        }
        
        for (int i = (int)num.size() - 1; i >= -1; i--) {
            int cur = i == -1 ? INT_MAX : num[i];
            while (stk.size() != 0 && cur > num[stk.top()]) {
                int tmp = stk.top();
                stk.pop();
                if (i == -1) {
                    leftMax[tmp] = INT_MAX;
                } else {
                    leftMax[tmp] = i;
                }
                
            
            }
            
            stk.push(i);
        }
        
        unordered_map<int , int> treeParent;
        for (int i = 0; i < num.size(); i++) {
            if (leftMax[i] == rightMax[i] && leftMax[i] == INT_MAX) {
                treeParent[num[i]] = INT_MAX;
            } else if (rightMax[i] == INT_MAX) {
                treeParent[num[i]] = num[leftMax[i]];
            } else if (leftMax[i] == INT_MAX ){
                treeParent[num[i]] = num[rightMax[i]];
            } else if (num[leftMax[i]] < num[rightMax[i]]){
                treeParent[num[i]] = num[leftMax[i]];
            } else if (num[leftMax[i]] > num[rightMax[i]]) {
                treeParent[num[i]] = num[rightMax[i]];

            }
        }
        return treeParent;
        
    }
    


};

int main(int argc, const char * argv[])
{

    vector<int> num = {2, 1, 5, 6, 0, 3};
    Solution su;
    unordered_map<int , int> result = su.constructMaxTree(num);
    unordered_map<int , int> :: iterator it = result.begin();
    
    for (; it != result.end(); it++) {
        cout << it->first << " parent is " << it->second << endl;
    }
    
    return 0;
}

