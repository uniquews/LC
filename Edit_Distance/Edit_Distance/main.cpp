//
//  main.cpp
//  Edit_Distance
//
//  Created by Shuai Wang on 6/28/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>


using namespace std;


// f[i][j]: minimum cost to transfer A[1...i] to B[1...j]

class Solution {
public:
    int minDistance(string word1, string word2) {
        int length1 = (int)word1.length();
        int length2 = (int)word2.length();
        
        return dp(length1, length2, word1, word2);
    }
    
    
    
    int dp(int length1, int length2, string word1, string word2){
        
        vector<vector<int>> f(length1+1, vector<int> (length2+1, 0));
        
        for(int i=0; i<=length1; i++){
            f[i][0] = i;
        }
        
        for(int i=0; i<=length2; i++){
            f[0][i] = i;
        }
        
        for(int i=1; i<=length1; i++){
            for(int j=1; j<=length2; j++){
                if(word1[i-1] == word2[j-1]){
                    f[i][j] = f[i-1][j-1];
                    
                }else{
                    int _min = min(f[i-1][j], f[i][j-1]);
                    f[i][j] = 1+ min(f[i-1][j-1], _min);
                }
                
            }
            
        }
        
        return f[length1][length2];
        
    }
};




int main(int argc, const char * argv[])
{

    string word1 = "";
    string word2 = "a";
    
    Solution s;
    cout << s.minDistance(word1, word2) << endl;
    return 0;
}

