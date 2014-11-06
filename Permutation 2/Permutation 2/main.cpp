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
#include <unordered_set>

using namespace std;



//class Solution {
//public:
//    vector<vector<int> > permuteUnique(vector<int> &num) {
//        if (num.size() == 0) {
//            return vector<vector<int>> {};
//        }
//        
//        sort(num.begin(), num.end());
//        
//        vector<int> eachResult;
//        vector<vector<int>> result;
//        unordered_set<int> visited;
//        dfs(0, num, eachResult, result, visited);
//        return result;
//    }
//    
//    void dfs(int step, vector<int> &num, vector<int> &eachResult, vector<vector<int>> &result, unordered_set<int> &visited) {
//        if (step == num.size()) {
//            result.push_back(eachResult);
//            return;
//        }
//        
//        for (int i = 0; i < num.size(); i++) {
//            if (visited.find(i) == visited.end()) {
//                visited.insert(i);
//                eachResult.push_back(num[i]);
//                dfs(step + 1, num, eachResult, result, visited);
//                eachResult.pop_back();
//                visited.erase(i);
//                while (i + 1 < num.size() && num[i] == num[i + 1]) {
//                    i++;
//                }
//                
//            }
//           
//        }
//        
//        
//        return;
//    }
//};

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int>> result;
        vector<int> eachResult;
        unordered_set<int> hashSet;
        
        dfs(0, num, result, eachResult, hashSet);
        return result;
    }
    
    void dfs(int index,vector<int> &num, vector<vector<int>> &result, vector<int> &eachResult, unordered_set<int> &hashSet) {
        if (index == num.size()) {
            result.push_back(eachResult);
            return;
        }
        
        for (int i = 0; i < num.size(); i++) {
            if (hashSet.find(i) == hashSet.end()) {
                eachResult.push_back(num[i]);
                hashSet.insert(i);
                dfs(index + 1, num, result, eachResult, hashSet);
                hashSet.erase(i);
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

    vector<int> num = {1, 1};
    Solution su;
    vector<vector<int> > result = su.permuteUnique(num);
    
    
    return 0;
}

