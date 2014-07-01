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

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<vector<bool>> f(s.length(), vector<bool> (s.length(), false));
        
//        for(int i=0; i< s.length(); i++){
//            string tempStr = s.substr(i, 1);
//            if(find(dict.begin(), dict.end(), tempStr)!=dict.end())
//                f[i][i] = true;
//        }
//        
        
        for(int length = 1; length<= s.length(); length++){
            for(int start = 0; start < s.length()-(length-1); start ++){
                int end = start + length; // not real
                string tempStr = s.substr(start, length);
                for(int k =0; k<length; k++){
                    string first = s.substr(start, k+1);
                    string second = s.substr(start+k+1, length-(k+1));
//                    cout << first << " "<< second << " " << endl;
                    if(!second.empty()){
                        if((f[start][start+k] == true || find(dict.begin(), dict.end(), first)!=dict.end()) && (f[start+k+1][start+length-1] == true || find(dict.begin(), dict.end(), second)!=dict.end()))
                            f[start][end-1] = true;

                    }else{
                        if((f[start][start+k] == true || find(dict.begin(), dict.end(), first)!=dict.end()))
                            f[start][start+k] = true;
                    }
                    
                }
            
            }
        
        
        }
        
        return f[0][s.length()-1];
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

