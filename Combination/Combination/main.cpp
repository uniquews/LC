//
//  main.cpp
//  Combination
//
//  Created by Shuai Wang on 8/30/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


//class Solution {
//public:
//    vector<vector<int> > combine(int n, int k) {
//        vector<int> num;
//        for (int i = 1; i <= n; i++) {
//            num.push_back(i);
//        }
//        
//        vector<vector<int>> result;
//        vector<int> eachResult;
//        
//        dfs(0, num, result, eachResult, 0, k);
//        return result;
//    }
//    
//    
//    void dfs (int start, vector<int> num, vector<vector<int>> &result, vector<int> &eachResult, int numOfEachResult, int k) {
//        if (numOfEachResult == k) {
//            result.push_back(eachResult);
//            return;
//        }
//        
//        for (int i = start; i < num.size(); i++) {
//            eachResult.push_back(num[i]);
//            dfs(i + 1, num, result, eachResult, numOfEachResult + 1, k);
//            eachResult.pop_back();
//        }
//        
//        return;
//    }
//};

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> eachResult;
        vector<int> num;
        for (int i = 1; i <= n; i++) {
            num.push_back(i);
        }
        
        
        dfs(num, 0, 0, eachResult, result, k);
        return result;
    }
    
    
    void dfs(vector<int> &num, int index, int step, vector<int> &eachResult, vector<vector<int>> &result, int k) {
        if (step == k) {
            result.push_back(eachResult);
            return;
        }
        
        for (int i = index; i < num.size(); i++) {
            eachResult.push_back(num[i]);
            dfs(num, i + 1, step + 1, eachResult, result, k);
            eachResult.pop_back();
        }
        
        return;
    }
};

int main(int argc, const char * argv[])
{

    int n = 1;
    int k = 1;
    Solution su;
    vector<vector<int>> result = su.combine(n, k);
    

    return 0;
}

