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
        int left=0;
        int right=0;
        if(s.size() == 0) return 0;
        if(s.size() ==1) return 1;
        unordered_map<char, bool> showUp; // map don't need to be initialized?
        int _max=1;
        
        while(left <s.size()  && right < s.size()){
            if(showUp[s[right]] == false){
                showUp[s[right]] = true;
                _max = max(_max, right -left +1);
                right++;
            }else{
                showUp[s[left]] = false;
                _max = max(_max, right-left);
                left++;
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

