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


//class Solution {
//public:
//    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
//        vector<vector<int>> result;
//        
//        sort(candidates.begin(), candidates.end(), myobject);
//        
//        vector<int> eachResult;
//        
//        int start =0;
//        int last = candidates[start];
//        
//        dfs(candidates, target, eachResult, result, start, last);
//        
//        return result;
//    }
//    
//    void dfs(vector<int> candidates, int target, vector<int> &eachResult, vector<vector<int>> &result, int &start, int last){
//        
//        if(target == 0) {
//        
//            result.push_back(eachResult);
//            return;
//        }
//        
//        for(int i = start; i<candidates.size(); i++){
//            int fetch = candidates[i];
//           
//            int last = eachResult.back();
//            if(fetch == last) continue;
//            int remain = target - fetch;
//            
//            if(remain < 0) return;
//            else{
//                eachResult.push_back(fetch);
//                dfs(candidates, remain, eachResult, result, i, last);
//                eachResult.pop_back();
//            
//            }
//            
//            
//
//        }
//    
//        return;
//    }
//    
//    
//    
//    static bool myfunction(int i, int j){
//        return (i < j);
//    }
//    
//};

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> eachResult;
        int start = 0;
        int end = candidates.size()-1;
        dfs(candidates, 0, target, eachResult, result);
        return result;
    }
    
    void dfs(vector<int> &candidates, int start, int target, vector<int> &eachResult, vector<vector<int>> &result){
        if(target == 0){
            result.push_back(eachResult);
            return;
        }
        
        for(int i=start; i<candidates.size(); i++){
            if(target < candidates[i])
                return;
            eachResult.push_back(candidates[i]);
            dfs(candidates, i, target - candidates[i], eachResult, result);
            eachResult.pop_back();
        }
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

