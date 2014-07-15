//
//  main.cpp
//  Subset
//
//  Created by Shuai Wang on 7/14/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int>> result;
        vector<int> level;
        sort(S.begin(), S.end());
        dfs(result, level, 0, S);
        
        return result;
    }
    
    void dfs(vector<vector<int>> &result, vector<int> &level, int step, vector<int> &S){
        if(S.size() == step){
            result.push_back(level);
            return;
        }
        
        dfs(result, level, step+1, S); // do not push S[step] in level
        level.push_back(S[step]);
        dfs(result, level, step+1, S);
        level.pop_back();
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

