//
//  main.cpp
//  Decode_Way
//
//  Created by Shuai Wang on 6/29/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//class Solution {
//public:
//    int numDecodings(string s) {
//        if(s.empty()) return 0;
//        
//        vector<int> f(s.size(), 0);
//        if(s[0]!='0') f[0] = 1;
//        if(s[1]!='0') f[1] = f[0];
//        if(isValid(s.substr(0, 2))) f[1]++;
//        
//        
//        for(int i=2; i<(int)s.length();i++){
//            if(s[i]!='0') f[i] += f[i-1];
//            if(isValid(s.substr(i-1, 2))) f[i]+=f[i-2];
//        
//        }
//        
//        return f[s.length()-1];
//    }
//    
//    
//    bool isValid(string s){
//        if(s[0] == '0') return false;
//        if(s[0] == '2' && s[1] >'6') return false;
//        if(s[0] > '2') return false;
//        
//        
//        return true;
//    
//    }    
//};

// Count[i] = Count[i-1]  if S[i-1] is a valid char
//       or   = Count[i-1]+ Count[i-2]  if S[i-1] and S[i-2] together is still a valid char.

class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0|| s[0] == '0')
            return 0;
        
        int prev = 0;
        int cur = 1;
        for(size_t i = 1; i<=s.size(); i++){
            if(s[i-1] == '0')
                cur = 0;
            if(i<2 || !(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <='6'))){
                prev = 0;
            }
            
            int temp = cur;
            cur = cur + prev;
            prev = temp;
            
            
        }
        return cur;
    }
};

int main(int argc, const char * argv[])
{
    string ss = "10";
    Solution su;
    cout << su.numDecodings(ss) << endl;
}

