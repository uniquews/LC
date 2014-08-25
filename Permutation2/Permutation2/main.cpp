//
//  main.cpp
//  Permutation2
//
//  Created by Shuai Wang on 7/17/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int>> result;
        vector<int> level;
        if(num.size() == 0) return result;
        vector<bool> visited(num.size(), false);
        sort(num.begin(), num.end());   // remember to sort it
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
                if(i>0 && num[i] == num[i-1] && visited[i-1] == 0)
                    continue;
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

    vector<int> num = {-1,-1,3,-1};
    Solution su;
    vector<vector<int>> result = su.permuteUnique(num);
    vector<vector<int>> :: iterator it = result.begin();
    for(; it!=result.end(); it++){
        vector<int>::iterator it2 = it->begin();
        for(;it2!=it->end(); it2++){
            cout << *it2<<" ";
        }
        
        cout << endl;
    }
    
    return 0;
}

