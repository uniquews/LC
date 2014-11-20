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
        
        unordered_set<char> hashSet;
        int result = 1;
        for (int end = 0; end < s.size(); end++) {
            if (hashSet.find(s[end]) == hashSet.end()) {
                hashSet.insert(s[end]);
                result = max(result, end - start + 1);
            } else {
                while (s[start] != s[end]) {
                    hashSet.erase(s[start]);
                    start++;
                }
                
                start++;
                
            }
            
        }
        return result;
    }
};

//超时的做法
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int start = 0;
        int result = 1;
        unordered_map<char, int> hashMap;
        while (start < s.size() - 1) {
            hashMap[s[start]] = 1;
            int end = start + 1;
            while (end < s.size() && hashMap[s[end]] < 1) {
                hashMap[s[end]]++;
                end++;
            }
            
            result = max(result, end - start);
            while (s[start] != s[end]) {
                start++;
            }
            start++;
            hashMap.clear();
        }
        return result;
    }
};


int main(int argc, const char * argv[])
{

    // insert code here...
    string s = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
//
//    string s = "aaa";
//      string s = "abcabcbb";
    
//    string s = "hchzvfrkmlnozjk";
    Solution su;
    cout << su.lengthOfLongestSubstring(s);
    return 0;
}

