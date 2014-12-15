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
        if (S.size() == 0 || T.size() == 0) {
            return 0;
        }
        
        if (S.size() < T.size()) {
            return 0;
        }
        
        vector<vector<int>> f(S.size(), vector<int> (T.size(), 0));
        
        if (S[0] == T[0]) {
            f[0][0] = 1;
        } else {
            f[0][0] = 0;
        }
        
        for (int i = 1; i < S.size(); i++) {
            f[i][0] = f[i - 1][0];
            if (S[i] == T[0]) {
                f[i][0] += 1;
            }
        }
        
        for (int i = 1; i < S.size(); i++) {
            for (int j = 1; j < T.size(); j++) {
                f[i][j] = f[i - 1][j];
                if (S[i] == T[j]) {
                    f[i][j] += f[i - 1][j - 1];
                }
                
            }
        }
        
        return f[S.size() - 1][T.size() - 1];
    }
};


//class Solution {
//public:
//    int numDistinct(string S, string T) {
//        if (S.size() == 0 || T.size() == 0) {
//            return 0;
//        }
//        
//        if (S.size() < T.size()) {
//            return 0;
//        }
//        
//        vector<vector<int>> f(S.size() + 1, vector<int> (T.size() + 1, 0));
//        
//        for (int i = 0; i <= S.size(); i++) {
//            f[i][0] = 1;
//        }
//        
//        for (int i = 1; i <= S.size(); i++) {
//            for (int j = 1; j <= T.size(); j++) {
//                f[i][j] = f[i - 1][j];
//                if (S[i - 1] == T[j - 1]) {
//                    f[i][j] += f[i - 1][j - 1];
//                }
//            }
//        }
//        
//        return f[S.size()][T.size()];
//    }
//};

int main(int argc, const char * argv[])
{

//    string S = "baa";
//    string T = "a";
//    string S = "rabbbit";
//    string T = "rabbit";
    
    string S = "aabb";
    string T = "ab";
    Solution ss;
    cout << ss.numDistinct(S, T) << endl;
    return 0;
}

