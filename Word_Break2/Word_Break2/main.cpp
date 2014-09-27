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
        unordered_map<int, vector<string>> *_map = new unordered_map<int, vector<string>>();
        
        int n = (int)s.size();
        vector<string> *init= new vector<string> ();
        init->push_back("");
        _map->insert({n, *init});
        
        for (int i = n - 1; i >= 0; i--) {
            vector<string> *tmp = new vector<string> ();
            for (int j = i; j < n; j++) {
                if (dict.find(s.substr(i, j - i + 1)) != dict.end()) {
                    vector<string> later = _map->at(j + 1);
                    for (auto str : later) {
                        string result = s.substr(i, j - i + 1).append(str.size() == 0 ? "" : " ").append(str);
                        tmp->push_back(result);
                    }
                
                }
            }
            
            _map->insert({i, *tmp});
            
        }
        
        return _map->at(0);
    }
    
};

int main(int argc, const char * argv[])
{

    string s = "aaaaaaa";
    unordered_set<string> dict = {"aaaa", "aaa"};
    Solution su;
    vector<string> result = su.wordBreak(s, dict);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}

