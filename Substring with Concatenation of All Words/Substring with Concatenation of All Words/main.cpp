//
//  main.cpp
//  Substring with Concatenation of All Words
//
//  Created by Shuai Wang on 6/1/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        map<string, int> neededCount;
        map<string, int> existedCount;
        vector<int> result;
        
        for(int i=0; i<L.size(); i++){
            neededCount[L.at(i)]++;
        }
        
        int eachLength = (int)L.back().size();
        int numOfTarget = (int)L.size();
        
        if(numOfTarget==0) return result;
        
        for(int i=0; i<(int)S.size()-numOfTarget*eachLength+1; i++){
            existedCount.clear();
            int j=0;
            for(;j<numOfTarget;j++){
                string temp = S.substr(i+j*eachLength, eachLength);
                if(neededCount.find(temp)!=neededCount.end()){ //find it
                    existedCount[temp]++;
                }
                else
                    break;
                if(existedCount[temp] > neededCount[temp])
                    break;
                
            }
            
            if(j==numOfTarget)
                result.push_back(i);
        }
        
        return result;
    }
};

int main(int argc, const char * argv[])
{

 
    return 0;
}

