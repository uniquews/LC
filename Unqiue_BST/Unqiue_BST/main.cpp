//
//  main.cpp
//  Unqiue_BST
//
//  Created by Shuai Wang on 7/18/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> f(n + 1);
        f[0] = 1;
        f[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            int temp = i - 1;
            for (int j = 0; j <= temp; j++) {
                f[i] += f[j] * f[temp - j];
            }
        }
        
        return f[n];
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

