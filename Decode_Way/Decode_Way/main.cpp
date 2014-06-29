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

class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;
        
        vector<int> f(s.size(), 0);
        if(s[0]!='0') f[0] = 1;
        if(s[1]!='0') f[1] = f[0];
        if(isValid(s.substr(0, 2))) f[1]++;
        
        
        for(int i=2; i<(int)s.length();i++){
            if(s[i]!='0') f[i] += f[i-1];
            if(isValid(s.substr(i-1, 2))) f[i]+=f[i-2];
        
        }
        
        return f[s.length()-1];
    }
    
    
    bool isValid(string s){
        if(s[0] == '0') return false;
        if(s[0] == '2' && s[1] >'6') return false;
        if(s[0] > '2') return false;
        
        
        return true;
    
    }
};

int main(int argc, const char * argv[])
{

    string s = "100";
    Solution ss;
    cout << ss.numDecodings(s) << endl;
    return 0;
}

