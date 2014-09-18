//
//  main.cpp
//  Longest Consecutive Sequence
//
//  Created by Shuai Wang on 9/17/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int maxLength = 0;
        unordered_map<int, bool> used;
        for (auto i : num) {
            used[i] = false;
        }
        
        for (auto i : num) {
            int len = 1;
            if (used[i] == true) {
                continue;
            }
            
            used[i] = true;
            int j = i + 1;
            while (used.find(j) != used.end()) {
                used[j] = true;
                j++;
                len++;
            }
            
            j = i - 1;
            while (used.find(j) != used.end()) {
                used[j] = true;
                j--;
                len++;
            }
            
            maxLength = max(maxLength, len);
            
        }
        
        return maxLength;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

