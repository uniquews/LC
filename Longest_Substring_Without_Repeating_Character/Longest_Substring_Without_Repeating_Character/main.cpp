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

//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        int left=0;
//        int right=0;
//        if(s.size() == 0) return 0;
//        if(s.size() ==1) return 1;
//        unordered_map<char, bool> showUp; // map don't need to be initialized?
//        int _max=1;
//        
//        while(left <s.size()  && right < s.size()){
//            if(showUp[s[right]] == false){
//                showUp[s[right]] = true;
//                _max = max(_max, right -left +1);
//                right++;
//            }else{
//                showUp[s[left]] = false;
//                _max = max(_max, right-left);
//                left++;
//            }
//        }
//        
//        return _max;
//    }
//    
//};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 1;
        if (s.size() <= 1) {
            return s.size();
        }
        
        unordered_map<int, bool> exist;
        exist[s[0]] = true;
        
        int maxLen = 1;
        
        while (left < s.size() && right < s.size()) {
            if (exist.find(s[right]) == exist.end() || exist[s[right]] == false) {
                exist[s[right]] = true;
                maxLen = max(right - left + 1, maxLen);
                right++;
            } else {
                exist[s[left]] = false;
                left++;
                maxLen = max(maxLen, right - left + 1);
            }
        }
        
        return maxLen;
    }
};


int main(int argc, const char * argv[])
{

    // insert code here...
//    string s = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
    
//    string s = "aaa";
    
    string s = "hchzvfrkmlnozjk";
    Solution su;
    cout << su.lengthOfLongestSubstring(s);
    return 0;
}

