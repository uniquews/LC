//
//  main.cpp
//  Subset2
//
//  Created by Shuai Wang on 7/15/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;


class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        if (S.size() == 0) {
            return vector<vector<int>> {};
        }
        
        sort(S.begin(), S.end());
        
        vector<vector<int>> result;
        vector<int> eachResult;
        
        result.push_back(eachResult);
        dfs(S, result, eachResult, 0);
        return result;
    }
    
    void dfs(vector<int> S, vector<vector<int>> &result, vector<int> &eachResult, int cur) {
        if (cur == S.size()) {
            return;
        }
        
        for (int i = cur; i < S.size(); i++) {
            eachResult.push_back(S[i]);
            result.push_back(eachResult);
            dfs(S, result, eachResult, i + 1);  // i + 1 not start + 1
            eachResult.pop_back();
            
            while (i + 1 < S.size() && S[i] == S[i + 1]) {
                i++;
            }
        }
        return;
    }
};

int main(int argc, const char * argv[])
{

    vector<int> S={1,1};
    Solution su;
    su.subsetsWithDup(S);
    return 0;
}

