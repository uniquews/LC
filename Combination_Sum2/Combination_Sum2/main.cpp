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


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> result;
        vector<int> level;
        
        if (num.size() == 0) {
            return result;
        }
        
        sort(num.begin(), num.end());
        
        dfs(num, result, level, 0, target);
        
        return result;
    }
    
    void dfs(vector<int> &num, vector<vector<int>> &result, vector<int> &level, int step, int target) {
        
        if (target == 0) {
            result.push_back(level);
            return;
        }
        
        if (step == num.size()) {
            return;
        }
        
        if (target < num[step]) {
            return;
        }
        
        for (int i = step; i < num.size(); i++) {
            level.push_back(num[i]);
            dfs(num, result, level, i + 1, target - num[i]);
            level.pop_back();
            
            while (i < num.size() - 1 && num[i] == num[i + 1]) {
                i++;
            }
        }
    }
    
};

int main(int argc, const char * argv[])
{

    // insert code here...
//    vector<int> a= {1, 1};
//    int target =2;
//    Solution s;
//    vector<vector<int>> result = s.combinationSum2(a, target);
//    vector<vector<int>> :: iterator it = result.begin();
//    for(; it!=result.end(); it++){
//        vector<int> ::iterator it2 = it->begin();
//        for(; it2!=it->end(); it2++){
//            cout << *it2 << " ";
//        }
//        
//        cout << endl;
//    }
    
    vector<int> a= {1, 2};
    int target =4;
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

