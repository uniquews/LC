//
//  main.cpp
//  Longest_Palindrome
//
//  Created by Shuai Wang on 7/6/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//class Solution {
//public:
//    string longestPalindrome(string s) {
//        int length = (int)s.size();
//        //        vector<vector<int>> P(length, vector<int> (length, 0));
//        int P[length][length];
//        memset(P, 0, length*length*sizeof(int));
//        int maxLength = 0;
//        int start = 0;
//        int end = 0;
//        
//        for(int i=0; i<length; i++){
//            for(int j=0; j< i; j++){
//                P[j][i] = (s[i] == s[j] && (i-j<2 || P[j+1][i-1]));
//                if(maxLength < i-j+1 && P[j][i]){
//                    maxLength = i-j+1;
//                    start = j;
//                    end = i;
//                }
//            }
//            
//            P[i][i]  =1;
//        }
//        
//        return s.substr(start, end-start+1);
//    }
//    
//};

class Solution {
public:
    string longestPalindrome(string s) {
        int maxLength = 0;
        string result = "";
        vector<vector<bool>> f(s.size(), vector<bool> (s.size(), false));
        
        for (int i = 0; i < s.size(); i++) {
            f[i][i] = true;
        }
        
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j] && (j - i <= 2 || f[i + 1][j - 1])) {
                    f[i][j] = true;
                    if (j - i + 1 > maxLength) {
                        maxLength = j - i + 1;
                        result = s.substr(i, maxLength);
                    }
                    
                }
            }
        }
        
        return result;
        
    }
};

int main(int argc, const char * argv[])
{
    
    string s="ccc";
    Solution su;
    cout << su.longestPalindrome(s)<< endl;
    return 0;
}

