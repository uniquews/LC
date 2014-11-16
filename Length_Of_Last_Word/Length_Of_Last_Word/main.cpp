//
//  main.cpp
//  Length_Of_Last_Word
//
//  Created by Shuai Wang on 8/1/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;

//class Solution {
//public:
//    int lengthOfLastWord(const char *s) {
//        int len = strlen(s);
//        int end = len - 1;
//        while (end >= 0 && s[end] == ' ') {
//            end--;
//        }
//        
//        if (end < 0) {
//            return 0;
//        }
//        
//        int start = end;
//        while (start >= 0 && s[start] != ' ') {
//            start--;
//        }
//        
//        return end - start;
//    }
//};

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = (int)strlen(s);
        int end = len - 1;
        while (end >= 0 && s[end] == ' ') {
            end--;
        }
        
        
        if (end < 0) {
            return 0;
        }
        
        int start = end;
        while (start >= 0 && s[start] != ' ') {
            start--;
        }
        
        return end - start;
        
    }
};

int main(int argc, const char * argv[])
{

    char *s = "a ";
    Solution su;
    cout << su.lengthOfLastWord(s) << endl;
    return 0;
}

