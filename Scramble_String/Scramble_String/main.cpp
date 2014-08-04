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

class Solution {
public:
    
    int CHAR_SIZE = 26;
    
    bool isScramble(string s1, string s2) {
        return isScrambleHelper(s1, s2);
    }
    
    bool isScrambleHelper(string &s1, string &s2) {
        if (s1.size() != s2.size())
            return false;
        if (s1 == s2)
            return true;
        
        int size = s1.size();
        vector<int> bucket(CHAR_SIZE, 0);
        string s11, s12, s21, s22;
        
        // Check wheter they have the same chars
        for (int i = 0; i < s1.size(); ++i) {
            bucket[s1[i] - 'a'] += 1;
            bucket[s2[i] - 'a'] -= 1;
        }
        for (int i = 0; i < CHAR_SIZE; ++i) {
            if (bucket[i] != 0)
                return false;
        }
        
        
        for (int i = 1; i < size; ++i) {
            s11 = s1.substr(0, i);
            s12 = s1.substr(i);
            
            s21 = s2.substr(0, i);
            s22 = s2.substr(i);
            if (isScrambleHelper(s11, s21) && isScrambleHelper(s12, s22))
                return true;
            
            s21 = s2.substr(size - i);
            s22 = s2.substr(0, size - i);
            if (isScrambleHelper(s11, s21) && isScrambleHelper(s12, s22))
                return true;
        }
        
        return false;
    }
    
    
};



int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

