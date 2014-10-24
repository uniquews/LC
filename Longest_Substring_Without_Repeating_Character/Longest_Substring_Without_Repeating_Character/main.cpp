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
#include <unordered_set>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }
        
        int start = 0;
        int end = 0;
        int result = INT_MIN;
        unordered_set<char> hashSet;
        while (end != s.size()) {
            if (hashSet.find(s[end]) == hashSet.end()) {
                hashSet.insert(s[end]);
                result = max(result, end -start + 1);
                end++;
                
            } else {
                while (s[start] != s[end]) {
                    hashSet.erase(s[start]);
                    start++;
                }
                
                start++;
                result = max(result, end -start + 1);
                end++;
                
            }
        }
        
        return result;
    }
};
int main(int argc, const char * argv[])
{

    // insert code here...
//    string s = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
//
//    string s = "aaa";
//      string s = "abcabcbb";
    
    string s = "hchzvfrkmlnozjk";
    Solution su;
    cout << su.lengthOfLongestSubstring(s);
    return 0;
}

