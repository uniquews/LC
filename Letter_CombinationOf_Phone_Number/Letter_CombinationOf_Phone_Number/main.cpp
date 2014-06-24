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

class Solution{
    
public:
    
    unordered_map<string, vector<string>> _map = {{"1", {""}}, {"2", {"a", "b", "c"}},
        {"3", {"d", "e", "f"}}, {"4", {"g", "h", "i"}}, {"5", {"j", "k", "l"}}, {"6", {"m", "n", "o"}}, {"7", {"p", "q", "r", "s"}}, {"8", {"t", "u", "v"}}, {"9", {"w", "x", "y", "z"}}, {"0", {" "}}};
    
    
    void ouput_map(){
        vector<string> keys;
        vector<vector<string>> values;
        
        for(auto kv: this->_map){
            keys.push_back(kv.first);
            values.push_back(kv.second);
            
        }
        
        for(auto key:keys){
            cout << key << " ";
        }
        cout << endl;
        
        
        for(auto value: values){
            vector<string> :: iterator it = value.begin();
            for(; it!=value.end(); it++){
                cout << *it << " ";
            }
            
            cout << endl;
        
        }
        
        return;
    
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        int start = 0;
        string eachStr;
        dfs(digits, start, eachStr, result);
        
        return result;
    }
    
    
    void dfs(string s, int start, string &eachStr, vector<string> &result){
        if(start == s.length()){
            result.push_back(eachStr);
            return;
        }
        
        string fetch = s.substr(start, 1);
        unordered_map<string, vector<string>> ::iterator numToDigits = this->_map.find(fetch);
        vector<string> digitsStr = numToDigits->second;
        for(int i = 0; i< digitsStr.size(); i++){
            eachStr.append(digitsStr[i]);
            dfs(s, start +1, eachStr, result);
            eachStr.pop_back();
            
        }
    
    }

};

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

