//
//  main.cpp
//  Gray Code
//
//  Created by Shuai Wang on 9/18/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        int size = 1 << n; //移位
        for(int i=0; i<size; i++){
            int tmp = i^(i>>1);
            result.push_back(tmp);
        }
        
        return result;
    }
};

int main(int argc, const char * argv[])
{

    int n = 2;
    Solution su;
    su.grayCode(n);
    return 0;
}

