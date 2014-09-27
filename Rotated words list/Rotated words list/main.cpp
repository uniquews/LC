//
//  main.cpp
//  Rotated words list
//
//  Created by Shuai Wang on 9/27/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    void rotatedStr(string &s) {
        std::reverse(s.begin(), s.end());
        for (int i = 0; i < s.size(); i++) {
            while (i < s.size() && s[i] == ' ') {
                i++;
            }
            
            int endIndex = i;
            while (endIndex < s.size() && s[endIndex] != ' ') {
                endIndex++;
            }
            
            reverse(s, i, endIndex - 1);
            
            i = endIndex;
      
        }
        
        
        return;
    }
    
    void reverse(string &s, int start, int end) {
        while (start <= end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
        
        return;
    
    }
};

int main(int argc, const char * argv[])
{

    Solution su;
    string s = "   I     love you  ";
    su.rotatedStr(s);
    cout << s << endl;
    return 0;
}

