//
//  main.cpp
//  Word_Ladder_II
//
//  Created by Shuai Wang on 9/16/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<string> curLevel;
        vector<string> nextLevel;
        unordered_map<string, vector<string>> father;
        unordered_set<string> visited;
        vector<vector<string>> result;
        vector<string> eachResult;
        
        bool found = false;
        
        curLevel.push_back(start);
        
        
        while (curLevel.empty() == false) {
            if(find(curLevel.begin(), curLevel.end(), end)!=curLevel.end())
                return result;
            
            for(auto str: curLevel){
                visited.insert(str);
            }
            
            while (curLevel.empty() == false) {
                string current = curLevel.back();
                curLevel.pop_back();
                
                for (int i = 0; i < current.size(); i++) {
                    for (char tri = 'a'; tri <= 'z'; tri++) {
                        string tmp = current;
                        if (tmp[i] == tri) {
                            continue;
                        }
                        
                        tmp[i] = tri;
                        
                        
                        if (tmp == end) {
                            eachResult.push_back(tmp);
                            father[tmp].push_back(current);
                            getResult(tmp, father, result, eachResult);
                            eachResult.pop_back();
                            father.erase(tmp);
                            found  = true;
                            break;
                        }
                        
                        if (dict.find(tmp) != dict.end() && visited.count(tmp) == 0) {
                            if (find(nextLevel.begin(), nextLevel.end(), tmp) == nextLevel.end()) {
                                nextLevel.push_back(tmp);
                            }
                            father[tmp].push_back(current);
                            
                        }
                    }
                }
                
            }
            
            if (found) {
                nextLevel.clear();
            } else {
                curLevel = nextLevel;
                nextLevel.clear();
            }
            
        }
        
        return result;
    }
    
    
    void getResult(string str, unordered_map<string, vector<string>> &father, vector<vector<string>> &result, vector<string> &eachResult) {
        
        
        if (father.find(str) == father.end()) { // this is the start string
            reverse(eachResult.begin(), eachResult.end());
            result.push_back(eachResult);
            reverse(eachResult.begin(), eachResult.end());
            return;
        }
        
        
        vector<string> allFathers = father[str];
        for (auto f : allFathers) {
            eachResult.push_back(f);
            getResult(f, father, result, eachResult);
            eachResult.pop_back();
        }
        
        return;
    }
};

int main(int argc, const char * argv[])
{

    string start = "red";
    string end = "tax";
    unordered_set<string> dict = {"ted","tex","red","tax","tad","den","rex","pee"};
    Solution su;
    vector<vector<string>> result = su.findLadders(start, end, dict);
    for (int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        
        cout << endl;
    }
    return 0;
}

