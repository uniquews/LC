//
//  main.cpp
//  Permutation
//
//  Created by Shuai Wang on 7/17/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> result;
        vector<int> level;
        if(num.size() == 0) return result;
        vector<bool> visited(num.size(), false);
        dfs(result, level, 0, visited, num);
        
        return result;
    }
    
    
    void dfs(vector<vector<int>> &result, vector<int> &level, int step, vector<bool> &visited, vector<int> &num){
        
        
        if(step == num.size()){
            result.push_back(level);
            return;
        }

        for(int i = 0; i<num.size(); i++){
            if(visited[i] == false){
                visited[i]  = true;
                level.push_back(num[i]);
                dfs(result, level, step+1, visited, num); //!!!!!step +1  not i+1
                level.pop_back();
                visited[i]  = false;
            }
            
            
        }
    }
};

int main(int argc, const char * argv[])
{

    vector<int> num = {0,1};
    Solution su;
    su.permute(num);
    return 0;
}

