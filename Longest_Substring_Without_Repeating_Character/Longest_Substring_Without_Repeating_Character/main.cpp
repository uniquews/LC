//
//  main.cpp
//  Longest_Substring_Without_Repeating_Character
//
//  Created by Shuai Wang on 7/10/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_map<char, int> showUp;
        
        for(char temp = 'a'; temp <='z'; temp++){
            showUp[temp] = -1;
        }
        
        
        vector<int> f(s.size(), 0);
        f[0] = 1;
        int _max  = 0;
        showUp[s[0]] = 0;
        
        for(int i=1; i<s.size();){
            if(showUp[s[i]] !=-1){
                f[i] = 1;
                int lastPosition = showUp[s[i]];
                for(int j = i; j>=lastPosition; j--){
                    showUp[s[j]] = -1;
                }
                i = lastPosition+1;
            }else{
                f[i] = f[i-1] +1;
                showUp[s[i]] = i;
                _max = max(f[i], _max);
                i++;
            }
        }
        
        return _max;
    }
};


int main(int argc, const char * argv[])
{

    // insert code here...
//    string s = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
    
    string s = "aaa";
    Solution su;
    cout << su.lengthOfLongestSubstring(s);
    return 0;
}

