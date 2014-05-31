//
//  main.cpp
//  MinimumWindowSubstring
//
//  Created by Shuai Wang on 5/30/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        // check some edge case
        // The string S is empty
        if(S.empty()) return "";
        //The string T is empty
        if(T.empty()) return "";
        
        //if S'size is smaller than T's size
        if(S.size() < T.size())
            return "";
        
        // Then find the smallest window. There are two cases: find it or not
        const int ASCII_MAX = 256; //Total 256 char
        int existed_count[ASCII_MAX];
        int needed_count[ASCII_MAX];
        
        fill(existed_count, existed_count+ASCII_MAX, 0); //Initialize
        fill(needed_count, needed_count+ASCII_MAX, 0);
        
        for(int i =0; i<T.size(); i++){
            needed_count[T[i]]++; // collect the number of each char
        }
        
        int minWin = INT_MAX; // If not found, then remaing INT_MAX;
        int minStart = 0;
        int wnd_start=0;
        int wnd_end=0;
        int numOfSatisfied=0;
        
        for(; wnd_end<S.size(); wnd_end++){
            
            // S[wnd_end] is in the T
            if(needed_count[S[wnd_end]]>0){
                existed_count[S[wnd_end]]++; // whatever this is the nth, it aloways add 1
                if(existed_count[S[wnd_end]]<=needed_count[S[wnd_end]]){
                    numOfSatisfied++; // This is needed number for each char in T
                }
            }
            
            if(numOfSatisfied == T.size()){
                while((existed_count[S[wnd_start]]>needed_count[S[wnd_start]]) || needed_count[S[wnd_start]]==0){
                    existed_count[S[wnd_start]]--;
                    wnd_start++;
                }
                
                
                if(minWin>(wnd_end-wnd_start+1)){
                    minWin=wnd_end-wnd_start+1;
                    minStart=wnd_start;
                }
                
            }
        }
        if(minWin==INT_MAX) return "";
        else return S.substr(minStart, minWin);
        
    }
    
};

int main(int argc, const char * argv[])
{

    // insert code here...
   
    return 0;
}

