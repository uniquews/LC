//
//  main.cpp
//  Distinct_Subsequence
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
    int numDistinct(string S, string T) {
        if(S.length() < T.length()) return 0;
        if(S.length() == 0 || T.length() == 0) return 0;
        
        vector<vector<int>> f(S.length(), vector<int>(T.length(), 0));
        
        if(S[0] == T[0])
            f[0][0] =1;
        else
            f[0][0] = 0;
        
        for(int i=1; i<S.length(); i++){
            if(S[i] == T[0])
                f[i][0] = f[i-1][0]+1;
            else
                f[i][0] = f[i-1][0];
        }
        
        for(int i=1; i< T.length(); i++)
            f[0][i]= 0;
        
        for(int i=1; i<S.length(); i++){
            for(int j=1; j<T.length(); j++){
                f[i][j] = f[i-1][j];
                if(S[i] == T[j])
                    f[i][j] += f[i-1][j-1];
            
            }
        
        }
        
        return f[S.length()-1][T.length()-1];
      
    }
};



int main(int argc, const char * argv[])
{

    string S = "baa";
    string T = "a";
    Solution ss;
    cout << ss.numDistinct(S, T) << endl;
    return 0;
}

