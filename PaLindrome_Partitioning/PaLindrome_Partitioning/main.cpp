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

//class Solution {
//public:
//    vector<vector<string>> partition(string s) {
//        vector<vector<string>> result;
//        vector<string> eachResult;
//        
//        if (s.size() == 0) {
//            result.push_back(eachResult);
//            return result;
//        }
//        
//        dfs(s, 0, s.size() - 1, eachResult, result);
//        return result;
//    }
//    
//    
//    void dfs(string s, int start, int end, vector<string> &eachResult, vector<vector<string>> &result) {
//        if (start > end) {
//            result.push_back(eachResult);
//            return;
//        }
//        
//        for (int i = start; i <= end; i++) {
//            if (isPP(s, start, i - start + 1)) {
//                eachResult.push_back(s.substr(start, i - start + 1));
//                dfs (s, i + 1, end, eachResult, result);
//                eachResult.pop_back();
//            }
//        }
//        
//        return;
//    }
//    
//    bool isPP (string s, int start, int length) {
//        string tmp = s.substr(start, length);
//        int left = 0;
//        int right = tmp.size() - 1;
//        while (left <= right) {
//            if (tmp[left] == tmp[right]) {
//                left ++;
//                right--;
//            } else {
//                return false;
//            }
//        }
//        
//        return true;
//    }
//};


//class Solution {
//public:
//    vector<vector<string>> partition(string s) {
//        if (s.size() == 0) {
//            return vector<vector<string>> {};
//        }
//        
//        vector<vector<string>> result;
//        vector<string> eachResult;
//
//        
//        dfs(s, 0, result, eachResult);
//        return result;
//    }
//    
//    void dfs(string &s, int cur, vector<vector<string>> &result, vector<string> &eachResult) {
//        if (cur >= s.size()) {
//            result.push_back(eachResult);
//            return;
//        }
//        
//        
//        for (int length = 1; length <= s.size() - cur; length++) {
//            string tmp = s.substr(cur, length);
//            if (isPP(s, cur, cur + length - 1) == true) {
//                eachResult.push_back(tmp);
//                dfs(s, cur +  length, result, eachResult);
//                eachResult.pop_back();
//            }
//        }
//        
//        return;
//        
//    }
//    
//    bool isPP(string &s, int start, int end) {
//
//        if (start == end) {
//            return true;
//        } else {
//            string tmp = s.substr(start, end - start + 1);
//            int left = start;
//            int right = end;
//            while (left < right) {
//                if (s[left] == s[right]) {
//                    left++;
//                    right--;
//                } else {
//                    return false;
//                }
//            }
//            
//            return true;
//        }
//    }
//
//    
//};

class Solution {
public:
    vector<vector<string>> partition(string s) {
        if (s.size() == 0) {
            return vector<vector<string>> {};
        }
        
        vector<vector<string>> result;
        vector<string> eachResult;
        
        vector<vector<bool>> isPP(s.size(), vector<bool> (s.size(), false));
        
        for (int i = 0; i < (int)s.size(); i++) {
            isPP[i][i] = true;
        }
        
        for (int i = (int)s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j] && (j - i <= 2 || isPP[i + 1][j - 1])) {
                    isPP[i][j] = true;
                }
            }
        }
        
        dfs(s, 0, result, eachResult, isPP);
        return result;
        
    }
    
    
    void dfs(string s, int start, vector<vector<string>> &result, vector<string> &eachResult, vector<vector<bool>> &isPP) {
        if (start == s.size()) {
            result.push_back(eachResult);
            return;
        }
        
        for (int i = start; i < s.size(); i++) {
            string tmp = s.substr(start, i - start + 1);
            if (isPP[start][i]) {
                eachResult.push_back(tmp);
                dfs(s, i + 1, result, eachResult, isPP);
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

