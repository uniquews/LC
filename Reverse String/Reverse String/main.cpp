//
//  main.cpp
//  Reverse String
//
//  Created by Shuai Wang on 9/20/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

//class Solution {
//public:
//    void reverseWords(string &s) {
//        if (s.size() == 0) {
//            return;
//        }
//        string result = "";
//        int start = 0;
//        int end = (int)s.size() - 1;
//        while (start <= end && s[start] == ' ') {
//            start++;
//        }
//        
//        if (start > end) {
//            s = result;
//            return;
//        }
//        
//        while (end >= start && s[end] == ' ') {
//            end--;
//        }
//        
//        
//        while (end >= start) {
//            while (end >= start && s[end] == ' ') {
//                end--;
//            }
//            int index = end;
//            while (index >= start && s[index] != ' ') {
//                index--;
//            }
//            
//            string tmp = s.substr(index + 1, end - index);
//            result.append(tmp).append(" ");
//            end = index - 1;
//        }
//        
//        result.resize(result.size() - 1);
//        s = result;
//        return;
//    }
//};

class Solution {
public:
    void reverseWords(string &s) {
        int start = 0;
        int end = (int)s.size() - 1;
        string result = "";
        while (start <= end && s[start] == ' ') {
            start++;
        }
        
        if (start > end) {
            s = "";
            return;
        }
        
        while (s[end] == ' ') {
            end--;
        }
        
        while (start <= end) {
            while (s[end] == ' ') {
                end--;
            }
            
            int index = end;
            while (index >= 0 && s[index] != ' ') {
                index--;
            }
            
            string tmp = s.substr(index + 1, end - index);
            result.append(tmp).append(" ");
            end = index;
            
        }
        
        result.resize(result.size() - 1);
        s = result;
        return;
    }
};
int main(int argc, const char * argv[])
{
    
    
//    string s = " 1";
//    string s1 = "   the sky is blue   ";
//    string s2 = " ";
    string s3 = "   a   b ";
    Solution su;
    su.reverseWords(s3);
    cout << s3 << endl;
    return 0;
}



