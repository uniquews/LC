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

struct myfunction{
    bool operator() (int i, int j){
        return (i< j);
    
    }

} myobject;


class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> result;
        
        sort(candidates.begin(), candidates.end(), myobject);
        
        vector<int> eachResult;
        
        int start =0;
        
        dfs(candidates, target, eachResult, result, start);
        
        return result;
    }
    
    void dfs(vector<int> candidates, int target, vector<int> &eachResult, vector<vector<int>> &result, int &start){
        
        if(target == 0) {
        
            result.push_back(eachResult);
            return;
        }
        
        for(int i = start; i<candidates.size(); i++){
            int fetch = candidates[i];
            int remain = target - fetch;
            
            if(remain < 0) return;
            else{
                eachResult.push_back(fetch);
                dfs(candidates, remain, eachResult, result, i);
                eachResult.pop_back();
            
            }

        }
    
        return;
    }
    
    
    
    static bool myfunction(int i, int j){
        return (i < j);
    }
    
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

