//
//  main.cpp
//  Unique BST
//
//  Created by Shuai Wang on 10/24/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> f(n + 1, 0);
        f[0] = 1;
        f[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= i - 1; j++) {
                f[i] += f[j] * f[i - 1 - j];
            }
        }
        
        return f[n];
    }
};

int main(int argc, const char * argv[])
{

    int n = 2;
    Solution su;
    cout << su.numTrees(n) << endl;
    
    return 0;
}

