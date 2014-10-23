//
//  main.cpp
//  Letter_CombinationOf_Phone_Number
//
//  Created by Shuai Wang on 6/23/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<string, vector<string>> keyboard = {{"0", {" "}}, {"1", {""}}, {"2", {"a", "b", "c"}}, {"3",  {"d", "e", "f"}},
        {"4", {"g", "h", "i"}}, {"5", {"j", "k", "l"}}, {"6", {"m", "n", "o"}},
        {"7", {"p", "q", "r", "s"}}, {"8", {"t", "u", "v"}}, {"9", {"w", "x", "y", "z"}}};
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return vector<string> {""};
        }
        
        string eachResult = "";
        vector<string> result;
        dfs(digits, 0, eachResult, result);
        return result;
    }
    
    void dfs(string digits, int index, string eachResult, vector<string> &result) {
        if (index == digits.size()) {
            result.push_back(eachResult);
            return;
        }
        
        string old = eachResult;
        string pivot = digits.substr(index, 1);
        vector<string> vals = keyboard[pivot];
        for (int i = 0; i < vals.size(); i++) {
            eachResult.append(vals[i]);
            dfs(digits, index + 1, eachResult, result);
            eachResult = old;
        }
        
        return;
        
    }
};
//class Solution {
//public:
//    vector<string> letterCombinations(string digits) {
//        unordered_map<string, vector<string>> keyboard = {{"1", {""}},
//            {"2", {"a", "b", "c"}},
//            {"3", {"d", "e", "f"}},
//            {"4", {"g", "h", "i"}},
//            {"5", {"j", "k", "l"}},
//            {"6", {"m", "n", "o"}},
//            {"7", {"p", "q", "r", "s"}},
//            {"8", {"t", "u", "v"}},
//            {"9", {"w", "x", "y", "z"}},
//            {"0", {" "}}
//        };
//        
//        vector<string> result;
//        string str = "";
//        dfs(0, digits, result, str, keyboard);
//        return result;
//    }
//    
//    void dfs(int step, string &digits, vector<string> &result, string &str, unordered_map<string, vector<string>> &keyboard) {
//        if (step == digits.size()) {
//            result.push_back(str);
//            return;
//        }
//        
//        vector<string> items = keyboard[digits.substr(step, 1)];
//        
//        for (int i = 0; i < items.size(); i++) {
//            string origin = str;
//            str.append(items[i]);
//            dfs(step + 1, digits, result, str, keyboard);
//            str = origin;
//        }
//        
//        return;
//        
//        
//    }
//    
//};
int main(int argc, const char * argv[])
{

    // insert code here...
//    std::cout << "Hello, World!\n";
    Solution s;
//    s.ouput_map();
    
    string d = "2";
    vector<string> r = s.letterCombinations(d);
    
    vector<string> :: iterator it = r.begin();
    for(; it!=r.end(); it++){
        cout << *it << " ";
    
    }
    
    cout << endl;
    
    return 0;
}

