//
//  main.cpp
//  UniqueBST
//
//  Created by Shuai Wang on 6/16/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> f(n+1, 0);
        f[0] = 1;
        f[1] = 1;
        int i =2;
        for(; i<=n; i++){
            for(int k = 1; k<=i; k++){
                f[i] += f[k-1]*f[i-k];
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

