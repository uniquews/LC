//
//  main.cpp
//  Subset
//
//  Created by Shuai Wang on 7/14/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        if (S.size() == 0) {
            return vector<vector<int>> {};
        }
        
        sort(S.begin(), S.end());
        vector<vector<int>> result;
        vector<int> eachResult;
        result.push_back(eachResult);
        
        dfs(S, 0, eachResult, result);
        return result;
    }
    
    void dfs(vector<int> &S, int start, vector<int> &eachResult, vector<vector<int>> &result) {
        if (start == S.size()) {
            return;
        }
        
        for (int i = start; i < S.size(); i++) {
            eachResult.push_back(S[i]);
            result.push_back(eachResult);
            dfs(S, i + 1, eachResult, result);
            eachResult.pop_back();
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

