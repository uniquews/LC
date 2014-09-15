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

using namespace std;

//class Solution {
//public:
//    vector<string> wordBreak(string s, unordered_set<string> &dict) {
//        if (s.size() == 0) {
//            return vector<string> {};
//        }
//        
//        vector<string> solution;
//        string result = "";
//        dfs(s, 0, s.length(), result, solution, dict);
//        
//        return solution;
//    }
//    
//    void dfs(string &s, int start, int len, string &result, vector<string> &solution, unordered_set<string> &dict) {
//        if (start == len) {
//            solution.push_back(result.substr(0, result.size()-1));//eliminate the last space
//        }else {
//            for (int i = start; i < len; i++) {
//                string tmp = s.substr(start, i - start + 1);
//                if (dict.find(tmp) != dict.end()) {
//                    result.append(tmp).append(" "); // remember this way
//                    dfs(s, i + 1, len, result, solution, dict);
//                    result.resize(0, result.length() - tmp.length() - 1); // minus the last space
//                }
//            }
//            
//        }
//        
//        return;
//        
//    }
//    
//};


class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        if (s.size() == 0) {
            return vector<string> {};
        }
        
        vector<string> solution;
        string result = "";
        vector<bool> possible(s.length() + 1, true);
        dfs(s, 0, s.length(), result, solution, dict, possible);
        
        return solution;
    }
    
    void dfs(string &s, int start, int len, string &result, vector<string> &solution, unordered_set<string> &dict, vector<bool> &possible) {
        if (start == len) {
            solution.push_back(result.substr(0, result.size()-1));//eliminate the last space
        }else {
            for (int i = start; i < len; i++) {
                string tmp = s.substr(start, i - start + 1);
                if (dict.find(tmp) != dict.end() && possible[i + 1]) {
                    result.append(tmp).append(" "); // remember this way
                    int beforeChange = solution.size();
                    dfs(s, i + 1, len, result, solution, dict, possible);
                    if (solution.size() == beforeChange) {
                        possible[i + 1] = false;
                    }
                    result.resize(result.length() - tmp.length() - 1); // minus the last space
                }
            }
            
        }
        
        return;
        
    }
    
};

int main(int argc, const char * argv[])
{

    string s = "aaaaaaa";
    unordered_set<string> dict = {"aaaa", "aaa"};
    Solution su;
    su.wordBreak(s, dict);
    return 0;
}

