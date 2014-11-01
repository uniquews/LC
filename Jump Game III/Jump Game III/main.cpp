//
//  main.cpp
//  Jump Game III
//
//  Created by Shuai Wang on 10/29/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> jumpGame3(vector<int> &A) {
        if (A.size() == 0) {
            return vector<vector<int>> {};
        }
        vector<vector<int>> result;
        vector<int> eachResult;
        unordered_set<int> hashSet;
        unordered_map<int, vector<int>> hashMap;
        vector<int> currentLevel;
        vector<int> nextLevel;
        bool isFound = false;
        
        currentLevel.push_back(0);
        
        while (currentLevel.size() != 0) {
            for (int i = 0; i < currentLevel.size(); i++) {
                hashSet.insert(currentLevel[i]);
            }
            
            for (int i = 0; i < currentLevel.size(); i++) {
                int curIndex = currentLevel[i];
                for (int i = 1; i <= A[curIndex]; i++) {
                    if (hashSet.find(curIndex + i) != hashSet.end()) {
                        continue;
                    }
                    
                    hashMap[curIndex + i].push_back(curIndex);
                    
                    if (find(nextLevel.begin(), nextLevel.end(), curIndex + i) == nextLevel.end()) {
                        nextLevel.push_back(curIndex + i);
                        
                    }
                    
                    if (curIndex + i == A.size() - 1) {
                        isFound = true;
                    }
                   
                }
            
            }
            if (isFound) {
                eachResult.push_back((int)A.size() - 1);
                getPath(hashMap, result, eachResult, (int)A.size() - 1);
                break;
            }
            
            
            currentLevel = nextLevel;
            nextLevel.clear();
        
        
        }
        

        return result;
       
    }
    
    void getPath(unordered_map<int, vector<int>> &hashMap, vector<vector<int>> &result, vector<int> &eachResult, int index) {
        if (hashMap.find(index) == hashMap.end()) {
            result.push_back(eachResult);
            return;
        }
        
        vector<int> fathers = hashMap[index];
        for (int i = 0; i < fathers.size(); i++) {
            eachResult.push_back(fathers[i]);
            getPath(hashMap, result, eachResult, fathers[i]);
            eachResult.pop_back();
        }
       
        return;
        
    }
    
    
};

int main(int argc, const char * argv[])
{

    Solution su;
    vector<int> A = {2,3,1,1,4};  // 只有一个min jump
//    vector<int> A = {2,3,2,3,4};
    vector<vector<int>> result = su.jumpGame3(A);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

