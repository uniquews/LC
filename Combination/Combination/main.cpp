//
//  main.cpp
//  Combination
//
//  Created by Shuai Wang on 7/17/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        
        vector<int> num;
        vector<int> visited(n, false);
        for(int i = 0; i<n; i++){
            num.push_back(i+1);
        }
        
        vector<vector<int>> result;
        vector<int> level;
        
        
        dfs(result, level, k, num, visited, 0);
        
        
        return result;
    }
    
    void dfs(vector<vector<int>> &result, vector<int> &level, int remain, vector<int> &num, vector<int> &visited, int start){
        if(remain == 0){
            result.push_back(level);
            return;
        }
        

        for(int i=start; i<num.size(); i++){
            if(visited[i] == false){
                visited[i] = true;
                level.push_back(num[i]);
                remain--;
                dfs(result, level, remain, num, visited, i+1);
                remain++;
                level.pop_back();
                visited[i] = false;
            }
        
        }
       
    }
};

int main(int argc, const char * argv[])
{

    int n =4;
    int k = 2;
    
    Solution su;
    vector<vector<int>> result = su.combine(n, k);
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

