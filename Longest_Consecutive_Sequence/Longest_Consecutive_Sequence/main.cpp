//
//  main.cpp
//  Longest_Consecutive_Sequence
//
//  Created by Shuai Wang on 7/1/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map<int, bool> used;
        for(auto i: num){
            used[i] = false;
        }
        
        int longest = 0;
        
        for(auto i: num){
            if(used[i])
                continue;
            int length = 1;
            used[i] = true;
            for(int j=i+1; used.find(j)!=used.end(); j++){
                used[j] = true;
                length++;
            }
            
            for(int j=i-1; used.find(j)!=used.end();j--){
                used[j] = true;
                length++;
            }
            
            longest = max(longest, length);
        }
        
        return longest;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

