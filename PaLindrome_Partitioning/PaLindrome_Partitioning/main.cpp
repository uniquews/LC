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
        
        if (s.size() == 0) {
            result.push_back(eachResult);
            return result;
        }
        
        dfs(s, 0, s.size() - 1, eachResult, result);
        return result;
    }
    
    
    void dfs(string s, int start, int end, vector<string> &eachResult, vector<vector<string>> &result) {
        if (start > end) {
            result.push_back(eachResult);
            return;
        }
        
        for (int i = start; i <= end; i++) {
            if (isPP(s, start, i - start + 1)) {
                eachResult.push_back(s.substr(start, i - start + 1));
                dfs (s, i + 1, end, eachResult, result);
                eachResult.pop_back();
            }
        }
        
        return;
    }
    
    bool isPP (string s, int start, int length) {
        string tmp = s.substr(start, length);
        int left = 0;
        int right = tmp.size() - 1;
        while (left <= right) {
            if (tmp[left] == tmp[right]) {
                left ++;
                right--;
            } else {
                return false;
            }
        }
        
        return true;
    }
};






int main(int argc, const char * argv[])
{

    
    string str = "b";
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
    
    return 0;
}

