//
//  main.cpp
//  PaLindrome_Partitioning
//
//  Created by Shuai Wang on 6/20/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> eachResult;
        vector<vector<bool>> isPP(s.size(), vector<bool> (s.size(), false));
        for (int i = 0; i < s.size(); i++) {
            isPP[i][i] = true;
        }
        
        for (int i = (int)s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j] && (j - i <= 2 || isPP[i + 1][j - 1])) {
                    isPP[i][j] = true;
                }
            }
        }
        
        
        dfs(s, 0, eachResult, result, isPP);
        return result;
    }
    
    
    
    void dfs(string s, int start, vector<string> &eachResult, vector<vector<string>> &result, vector<vector<bool>> &isPP) {
        if (start == s.size()) {
            result.push_back(eachResult);
            return;
        }
        
        for (int i = 1; i <= s.size() - start; i++) {
            string tmp = s.substr(start, i);
            if (isPP[start][i + start - 1]) {
                eachResult.push_back(tmp);
                dfs(s, i + start, eachResult, result, isPP);
                eachResult.pop_back();
            }
        }
        
        return;
    }
};




int main(int argc, const char * argv[])
{

    
    string str = "seeslaveidemonstrateyetartsnomedievalsees";
//    string str = "aab";
    cout << str.size() << endl;
    Solution s;
    vector<vector<string>> result = s.partition(str);
    
    vector<vector<string>>::iterator it = result.begin();
    for(; it!=result.end(); it++){
        vector<string>::iterator it2 = it->begin();
        for(; it2!=it->end();it2++){
        
            cout << *it2<< " ";
        }
        
        cout << endl;
    
    }
    
//     std::string str="aab";
//    int start = 1;
//    int end = 2;
//    std::string str2 = str.substr (start,end - start + 1);   // "generalities"
//    cout << str2 << endl;
    return 0;
}

