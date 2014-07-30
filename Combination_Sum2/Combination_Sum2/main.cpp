//
//  main.cpp
//  Combination_Sum2
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
    vector<vector<int>> combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> result;
        vector<int> eachResult;
        
        sort(num.begin(), num.end());
        
        int start = 0;
        
        dfs(num, start, target, eachResult, result);
        return result;
    }
    
    void dfs(vector<int> &num, int start, int target, vector<int> &eachResult, vector<vector<int>> &result){
        if(target == 0){
            result.push_back(eachResult);
            return;  //??
        }else{
            if(start +1 <= num.size()){
                for(int i=start; i<num.size();i++){
                    int fetch = num[i];
                    
                    int remain = target - fetch;
                    
                    if(remain < 0)
                        return;
                    eachResult.push_back(fetch);
                    dfs(num, i+1, target - fetch, eachResult, result);
                    eachResult.pop_back();
                    
                    while(i < num.size()-1 && num[i] == num[i+1]){
                        i++;
                    }
                }
            }
        }
        
        return;
    }
    
};

int main(int argc, const char * argv[])
{

    // insert code here...
    vector<int> a= {1, 1};
    int target =2;
    Solution s;
    vector<vector<int>> result = s.combinationSum2(a, target);
    vector<vector<int>> :: iterator it = result.begin();
    for(; it!=result.end(); it++){
        vector<int> ::iterator it2 = it->begin();
        for(; it2!=it->end(); it2++){
            cout << *it2 << " ";
        }
        
        cout << endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}

