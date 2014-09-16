//
//  main.cpp
//  Combination_Sum
//
//  Created by Shuai Wang on 6/23/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> result;
        vector<int> level;
        
        sort(candidates.begin(), candidates.end());
        
        if (candidates.size() == 0) {
            return result;
        }
        
        dfs(candidates, result, level, target, 0);
        
        return result;
    }
    
    void dfs(vector<int> &candidates, vector<vector<int>> &result, vector<int> &level, int target, int step) {
        if (target == 0) {
            result.push_back(level);
            return;
        }
        
        if (target < candidates[step]) {
            return;
        }
        
        for (int i = step; i < candidates.size(); i++) {
            level.push_back(candidates[i]);
            dfs(candidates, result, level, target - candidates[i], i);
            level.pop_back();
            
            while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1]) {
                i++;
            }
            
        }
        
        
    }
};



int main(int argc, const char * argv[])
{

    vector<int> candidates = {1,2, 2,3,4,5};
    Solution su;
    vector<vector<int>> result = su.combinationSum(candidates, 9);
    vector<vector<int>> :: iterator it = result.begin();
    for(; it != result.end(); it++) {
        vector<int> :: iterator it2 = it->begin();
        for(; it2 != it->end(); it2++) {
            cout << *it2 << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}

