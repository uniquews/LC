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
        vector<vector<int>> result;
        vector<int> level;
        result.push_back(level);
        sort(S.begin(), S.end());
        dfs(result, level, 0, S);
        
        return result;
    }
    
    void dfs(vector<vector<int>> &result, vector<int> &level, int step, vector<int> &S){
        for(int i = step; i<S.size(); i++){
            level.push_back(S[i]);
            result.push_back(level);
            if(i < S.size()-1){
                dfs(result,level, i+1, S);
            }
            level.pop_back();
            while(i<S.size()-1 && S[i] == S[i+1]){
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

