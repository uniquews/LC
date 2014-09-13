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

//class Solution{
//    
//public:
//    
//    unordered_map<string, vector<string>> _map = {{"1", {""}}, {"2", {"a", "b", "c"}},
//        {"3", {"d", "e", "f"}}, {"4", {"g", "h", "i"}}, {"5", {"j", "k", "l"}}, {"6", {"m", "n", "o"}}, {"7", {"p", "q", "r", "s"}}, {"8", {"t", "u", "v"}}, {"9", {"w", "x", "y", "z"}}, {"0", {" "}}};
//    
//    
//    void ouput_map(){
//        vector<string> keys;
//        vector<vector<string>> values;
//        
//        for(auto kv: this->_map){
//            keys.push_back(kv.first);
//            values.push_back(kv.second);
//            
//        }
//        
//        for(auto key:keys){
//            cout << key << " ";
//        }
//        cout << endl;
//        
//        
//        for(auto value: values){
//            vector<string> :: iterator it = value.begin();
//            for(; it!=value.end(); it++){
//                cout << *it << " ";
//            }
//            
//            cout << endl;
//        
//        }
//        
//        return;
//    
//    }
//    
//    vector<string> letterCombinations(string digits) {
//        vector<string> result;
//        int start = 0;
//        string eachStr;
//        dfs(digits, start, eachStr, result);
//        
//        return result;
//    }
//    
//    
//    void dfs(string s, int start, string &eachStr, vector<string> &result){
//        if(start == s.length()){
//            result.push_back(eachStr);
//            return;
//        }
//        
//        string fetch = s.substr(start, 1);
//        unordered_map<string, vector<string>> ::iterator numToDigits = this->_map.find(fetch);
//        vector<string> digitsStr = numToDigits->second;
//        for(int i = 0; i< digitsStr.size(); i++){
//            eachStr.append(digitsStr[i]);
//            dfs(s, start +1, eachStr, result);
//            eachStr.pop_back();
//            
//        }
//    
//    }
//
//};


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        unordered_map<string, vector<string>> keyboard = {{"0", {" "}},
            {"1", {""}},
            {"2", {"a", "b", "c"}},
            {"3", {"d", "e", "f"}},
            {"4", {"g","h","i"}},
            {"5", {"j", "k", "l"}},
            {"6", {"m", "n", "o"}},
            {"7", {"p", "q", "r", "s"}},
            {"8", {"t", "u", "v"}},
            {"9", {"w", "x", "y", "z"}}
        };
        
        
        if (digits.size() == 0) {
            return vector<string> {""};
        }
        
        vector<string> result;
        string str;
        dfs(digits, 0, result, str, keyboard);
        return result;
    }
    
    void dfs(string digits, int cur, vector<string> &result, string &str, unordered_map<string, vector<string>> &keyboard) {
        if (cur == digits.size()) {
            result.push_back(str);
            return;
        }
        
        for (int i = cur; i < digits.size(); i++) {
            
            string tmpStr = digits.substr(i, 1);
            vector<string> eachDigit = keyboard[tmpStr];
            for (int j = 0; j < eachDigit.size(); j++) {
                string tmp = eachDigit[j];
                string origin = str;
                str.append(tmp);
                dfs(digits, i + 1, result, str, keyboard);
                str = origin;
            }
        }
        
        return;
        
    }
    
};

int main(int argc, const char * argv[])
{

    // insert code here...
//    std::cout << "Hello, World!\n";
    Solution s;
//    s.ouput_map();
    
    string d = "22";
    vector<string> r = s.letterCombinations(d);
    
    vector<string> :: iterator it = r.begin();
    for(; it!=r.end(); it++){
        cout << *it << " ";
    
    }
    
    cout << endl;
    
    return 0;
}

