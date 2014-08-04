//
//  main.cpp
//  Word_Break
//
//  Created by Shuai Wang on 6/29/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>


// even more makeing sence version

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<vector<bool>> f(s.length(), vector<bool> (s.length(), false));
        
        int totalLength = s.length();
        
        for(int length = 1; length <= totalLength; length++){
            for(int start = 0; start <= totalLength - length; start++){
                int endIndex = start + length - 1;
                string tempStr = s.substr(start, length);
                for(int k = 1; k <= length; k++){
                    string first = s.substr(start, k);
                    if(start + k > endIndex){
                        if((f[start][start + k - 1] || find(dict.begin(), dict.end(), first) != dict.end())){
                            f[start][endIndex] = true;
                        }
                    }else{
                        string second = s.substr(start + k, length);
                        if((f[start][start + k -1] || find(dict.begin(), dict.end(), first) != dict.end()) &&
                           (f[start + k][start + length - 1] || find(dict.begin(), dict.end(), second)!= dict.end())){
                            f[start][endIndex] = true;
                        }
                        
                    }
                }
            }
        }
        
        return f[0][totalLength-1];
    }
};


int main(int argc, const char * argv[])
{

    string s = "leetcode";
    string trya = "";
    string ltt = "leet";
    unordered_set<string> _set ({"leet", "code"});
    
//    if(_set.find(ltt)!=_set.end())
//        cout << "vuhjbijbkj";
//    else
//        cout << "hh";
    
    
    Solution ss;
    cout << ss.wordBreak(s, _set)<< endl;
    
    return 0;
}

