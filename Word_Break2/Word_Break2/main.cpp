//
//  main.cpp
//  Word_Break2
//
//  Created by Shuai Wang on 6/30/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <unordered_map>

using namespace std;
//class Solution {
//public:
//    vector<string> wordBreak(string s, unordered_set<string> &dict) {
//        vector<string> result;
//        string eachResult = "";
//        vector<bool> possible (s.length() + 1, true);
//        dfs(s, 0, eachResult, result, dict, possible);
//        return result;
//    }
//    
//    void dfs(string &s, int index, string &eachResult, vector<string> &result, unordered_set<string> &dict, vector<bool> &possible) {
//        if (index == s.size()) {
//            eachResult.resize(eachResult.size() - 1);
//            result.push_back(eachResult);
//            return;
//        }
//        
//        for (int i = 1; i <= s.size() - index; i++) {
//            string tmp = s.substr(index, i);
//            if (dict.find(tmp) != dict.end() && possible[index + i]) {
//                string origin = eachResult;
//                eachResult.append(tmp).append(" ");
//                int beforeDfs = result.size();
//                dfs(s, index + i, eachResult, result, dict, possible);
//                if (result.size() == beforeDfs) {
//                    possible[index + i] = false;
//                }
//                eachResult = origin;
//            }
//        }
//        
//        return;
//    }
//};

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> result;
        string eachResult = "";
        vector<bool> possible(s.size() + 1, true);
        dfs(s, 0, result, eachResult, possible, dict);
        return result;
    }
    
    void dfs(string s, int index, vector<string> &result, string &eachResult, vector<bool> &possible, unordered_set<string> &dict) {
        if (index == s.size()) {
            eachResult.resize(eachResult.size() - 1);
            result.push_back(eachResult);
            return;
        }
        
        for (int i = 1; i <= (int)s.size() - index; i++) {
            string tmp = s.substr(index, i);
            if (dict.find(tmp) != dict.end() && possible[index + i]) {
                string origin = eachResult;
                eachResult.append(tmp).append(" ");
                int beforeDFS = (int)result.size();
                dfs(s, index + i, result, eachResult, possible, dict);
                if (result.size() == beforeDFS) {
                    possible[index + i] = false;
                }
                
                eachResult = origin;
            }
        }
        
        return;
    }
    
};

int main(int argc, const char * argv[])
{

//    string s = "aaaaaaa";
//    unordered_set<string> dict = {"aaaa", "aaa"};
    
    string s = "catsanddog";
    unordered_set<string> dict = {"cat", "cats", "and", "sand", "dog"};
    Solution su;
    vector<string> result = su.wordBreak(s, dict);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}

