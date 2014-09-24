//
//  main.cpp
//  Permutation 2
//
//  Created by Shuai Wang on 9/24/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        if (num.size() == 0) {
            return vector<vector<int>> {};
        }
        
        sort(num.begin(), num.end());
        
        vector<vector<int>> result;
        vector<int> eachResult;
        unordered_map<int, bool> visited;
        dfs(num, 0, result, eachResult, visited);
        return result;
        
    }
    
    void dfs(vector<int> &num, int step, vector<vector<int>> &result, vector<int> &eachResult, unordered_map<int, bool> &visited) {
        if (step == num.size()) {
            result.push_back(eachResult);
            return;
        }
        
        for (int i = 0; i < num.size(); i++) {
            if (visited[i] == false) {
                eachResult.push_back(num[i]);
                visited[i] = true;
                dfs(num, step + 1, result, eachResult, visited);
                eachResult.pop_back();
                visited[i] = false;
                
                while (i + 1 < num.size() && num[i] == num[i + 1]) {
                    i++;
                }
            }
            
            
        }
        
        return;
        
        
    }
};
int main(int argc, const char * argv[])
{

    vector<int> num = {1, 1};
    Solution su;
    su.permuteUnique(num);
    return 0;
}

