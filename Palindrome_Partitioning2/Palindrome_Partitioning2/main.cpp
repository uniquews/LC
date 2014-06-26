//
//  main.cpp
//  Palindrome_Partitioning2
//
//  Created by Shuai Wang on 6/25/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        
        vector<vector<bool>> Pa(s.length(), vector<bool> (s.length(), false));
        
        for (int i=(int)s.size()-1;i>=0;i--){
            for (int j=i;j<s.size();j++){
                if ((s[i]==s[j]) && (j-i<2 || Pa[i+1][j-1])){
                    Pa[i][j]=true;
                }else{
                    Pa[i][j]=false;
                }
            }
        }
        
        
        if(s.length() == 0 || s.length() == 1){
            return 0;
        }
        
//        for(int k = 0; k<s.length(); k++){
//            cout << s[k];
//        }
        
        vector<int> f(s.length(), 0);
        f[0] = 0;
        if(s[0] == s[1])
            f[1] = 0;
        else
            f[1] = 1;
        
        for(int i = 2; i<s.length(); i++){
            
            if(Pa[0][i]){
                f[i] = 0;
            
            }else{
                int tempMin = INT_MAX;
                for(int j =0; j<i; j++){
                    if(Pa[j+1][i]){
                        f[i] = f[j]+1;
                        if(tempMin > f[i])
                            tempMin = f[i];
                    }
      
                }
//                 f[i] = min(tempMin, f[i-1]+1);
                f[i]  = tempMin;
            }
            
        
        }
              
        return f[s.length()-1];
    }
    
//    bool isPa(string s, int start, int end, vector<vector<bool>> &Pa){
//        if(start == end) return true;
//        if(start == end-1){
//            if(s[start] == s[end])
//                return true;
//            else return false;
//        }
//        int i =start;
//        int j = end;
//        while(s[i] == s[j] && j>=i){
//            i++;
//            j--;
//        
//        }
//        
//        if(j<i){
////            Pa[start][end] = true;
//            return true;
//        }else{
////            Pa[start][end] = false;
//            return false;
//        }
//        
//        
//        
//    
//    }
    
    
};

int main(int argc, const char * argv[])
{

    string s = "aaabb";
    Solution su;
    cout << su.minCut(s) << endl;
    return 0;
}

