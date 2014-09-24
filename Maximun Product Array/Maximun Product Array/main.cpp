//
//  main.cpp
//  Maximun Product Array
//
//  Created by Shuai Wang on 9/23/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(int A[], int n) {
        if (n == 0) {
            return 0;
        }
        vector<int> f(n);
        vector<int> g(n);
        f[0] = A[0];
        g[0] = A[0];
        int result = f[0];
        
        for (int i = 1; i < n; i++) {
            int num1 = A[i];
            int num2 = A[i] * f[i - 1];
            int num3 = A[i] * g[i - 1];
            
            int tempMax = max(num1, num2);
            f[i] = max(tempMax, num3);
            
            int tempMin = min(num1, num2);
            g[i] = min(tempMin, num3);
            
            result = max(f[i], result);
        }
        
        return result;
    }
};

int main(int argc, const char * argv[])
{

    int A[] = {-2,3,-4};
    Solution su;
    cout << su.maxProduct(A, 3) << endl;
    return 0;
}

