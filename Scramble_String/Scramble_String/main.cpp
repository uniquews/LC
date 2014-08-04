//
//  main.cpp
//  Scramble_String
//
//  Created by Shuai Wang on 6/28/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

//class Solution {
//public:
//    
//    int CHAR_SIZE = 26;
//    
//    bool isScramble(string s1, string s2) {
//        return isScrambleHelper(s1, s2);
//    }
//    
//    bool isScrambleHelper(string &s1, string &s2) {
//        if (s1.size() != s2.size())
//            return false;
//        if (s1 == s2)
//            return true;
//        
//        int size = s1.size();
//        vector<int> bucket(CHAR_SIZE, 0);
//        string s11, s12, s21, s22;
//        
//        // Check wheter they have the same chars
//        for (int i = 0; i < s1.size(); ++i) {
//            bucket[s1[i] - 'a'] += 1;
//            bucket[s2[i] - 'a'] -= 1;
//        }
//        for (int i = 0; i < CHAR_SIZE; ++i) {
//            if (bucket[i] != 0)
//                return false;
//        }
//        
//        
//        for (int i = 1; i < size; ++i) {
//            s11 = s1.substr(0, i);
//            s12 = s1.substr(i);
//            
//            s21 = s2.substr(0, i);
//            s22 = s2.substr(i);
//            if (isScrambleHelper(s11, s21) && isScrambleHelper(s12, s22))
//                return true;
//            
//            s21 = s2.substr(size - i);
//            s22 = s2.substr(0, size - i);
//            if (isScrambleHelper(s11, s21) && isScrambleHelper(s12, s22))
//                return true;
//        }
//        
//        return false;
//    }
//    
//    
//};

class Solution{

public:
    bool isScramble(string s1, string s2){
        if(s1.length() != s2.length())
            return false;
        int length1 = (int)s1.length();
        int length2 = (int)s2.length();
        
        return dp(s1, s2, length1, length2);
    }
    
    bool dp(string s1, string s2, int length1, int length2){
        int sumLength = length1;
        vector<vector<vector<bool>>> f (sumLength+1, vector<vector<bool>> (length1+1, vector<bool> (length2+1, false)));
        for(int i=1; i<=sumLength; i++){
            for(int j = 0; j<length1; j++){
                    for(int k = 0; k<length2; k++){
                        if(i == 1){
                            if(s1[j] == s2[k]) {
                                f[1][j][k] = true;
                                continue;
                            }
                        }
                        
                        for(int extend = 1; extend <= i; extend++){
                            f[i][j][k] = ((f[extend][j][k] && f[i - extend][j+i][k+i]) || (f[i][j][k+sumLength-i] && f[i][j+i][k]));
                        }
                        
                    }
                }
            
         
        }
        
        return f[sumLength-1][length1-1][length2-1];
    }
};


int main(int argc, const char * argv[])
{

    string s1 = "abab";
    string s2 = "abab";
    
    Solution su;
    cout << su.isScramble(s1, s2) << endl;
    return 0;
}

