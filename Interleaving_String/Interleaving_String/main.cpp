//
//  main.cpp
//  Interleaving_String
//
//  Created by Shuai Wang on 6/28/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() == 0 && s2.length()==0 && s3.length() == 0)
            return true;

        
        if(s3.length() != s1.length() + s2.length())
            return false;
        
        vector<vector<bool>> f (s1.length()+1, vector<bool> (s2.length()+1, false));
        
        f[0][0] = true;
        
        for(int i=1; i<=(int)s1.length(); i++){
            f[i][0] = s1[i-1] == s3[i-1] && f[i-1][0];
        
        }
        
        for(int i=1; i<=(int)s2.length(); i++){
            f[0][i] = s2[i-1] == s3[i-1] && f[0][i-1];
        }
        
        for(int i=1; i<=(int)s1.length(); i++){
            for(int j = 1; j<=(int)s2.length(); j++){
                f[i][j] = (s1[i-1] == s3[i+j-1] && f[i-1][j]) ||
                (s2[j-1] == s3[i+j-1] && f[i][j-1]);
            
            }
            
        }
        
        return f[s1.length()][s2.length()];
        
    }
};

int main(int , const char * argv[])
{

    string s1="a";
    string s2 = "b";
    string s3 = "ab";
    
    Solution s;
    cout << s.isInterleave(s1, s2, s3);
    return 0;
}
