//
//  main.cpp
//  Pascal's Triangle II
//
//  Created by Shuai Wang on 6/1/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        int start = 0;
        for (int i = start; i <= rowIndex; i++) {
            if (i == 0) {
                result.push_back(1);
            } else {
                vector<int> :: iterator it = result.begin();
                result.insert(it, 0);
                result.push_back(0);
                for (int j = 0; j <= i; j++) {
                    result[j] = result[j] + result[j + 1];
                }
                
                result.pop_back();
            }
        }
        
        return result;
        
    }
};

int main(int argc, const char * argv[])
{

    int rowIndex = 2;
    Solution su;
    su.getRow(rowIndex);
    return 0;
}

