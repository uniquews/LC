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

class Solution{

public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> result;
        
        sort(num.begin(), num.end(), myobject);
        
        vector<int> eachResult;
        
        int start =0;
//        int last = INT_MIN;
        
        dfs(num, target, eachResult, result, start);
        
        return result;
    
    
    }

    
    void dfs(vector<int> candidates, int target, vector<int> &eachResult, vector<vector<int>> &result, int start){
        
        if(target == 0) {
            
//            if(!compareIn(eachResult, result))
            result.push_back(eachResult);
                
//            return;
        }
        
        if(start+1 <= candidates.size()){
            for(int i = start; i<candidates.size(); i++){
            int fetch = candidates[i];
            
            
//            if(fetch == last) continue;
            int remain = target - fetch;
            
            if(remain < 0) return;
            else{
                eachResult.push_back(fetch);
//                last = fetch;
                
                dfs(candidates, remain, eachResult, result, i+1);
                    
                
                eachResult.pop_back();
                
                while(i<candidates.size()-1 && candidates[i] == candidates[i+1])
                    i++;
     
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

