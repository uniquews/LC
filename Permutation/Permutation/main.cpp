//
//  main.cpp
//  Permutation
//
//  Created by Shuai Wang on 10/22/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        if (num.size() == 0) {
            return vector<vector<int>> {};
        }
        
        vector<vector<int>> result;
        vector<int> eachResult;
        unordered_set<int> visited;
        dfs(num, 0, result, eachResult, visited);
        return result;
    }
    
    
    void dfs(vector<int> &num, int index, vector<vector<int>> &result, vector<int> &eachResult, unordered_set<int> &visited) {
        if (index == num.size()) {
            result.push_back(eachResult);
            return;
        }
        
        for (int i = 0; i < num.size(); i++) {
            if (visited.find(i) == visited.end()) {
                eachResult.push_back(num[i]);
                visited.insert(i);
                dfs(num, index + 1, result, eachResult, visited);
                visited.erase(i);
                eachResult.pop_back();
            }
        }
        
        return;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

