//
//  main.cpp
//  Permutation2
//
//  Created by Shuai Wang on 7/17/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

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
        vector<bool> visited(num.size(), false);
        dfs(num, result, eachResult, 0, visited);
        
        return result;
    }
    
    void dfs(vector<int> &num, vector<vector<int>> &result, vector<int> &eachResult, int step, vector<bool> &visited) {
        if (step == num.size()) {
            result.push_back(eachResult);
            return;
        }
        
        for (int i = 0; i < num.size(); i++) {
            if (visited[i] == false) {
                eachResult.push_back(num[i]);
                visited[i] = true;
                dfs(num, result, eachResult, step + 1, visited);
                visited[i] = false;
                eachResult.pop_back();
                
                
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

    vector<int> num = {-1,-1,3,-1};
    Solution su;
    vector<vector<int>> result = su.permuteUnique(num);
    vector<vector<int>> :: iterator it = result.begin();
    for(; it!=result.end(); it++){
        vector<int>::iterator it2 = it->begin();
        for(;it2!=it->end(); it2++){
            cout << *it2<<" ";
        }
        
        cout << endl;
    }
    
    return 0;
}

