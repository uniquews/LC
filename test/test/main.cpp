//
//  main.cpp
//  test
//
//  Created by Shuai Wang on 6/3/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<=1) return n;
        int cur = 0;
        
        for(int i = 1; i< n; i++){
            if(A[cur] != A[i])
                A[cur++] = A[i];
            
        }
        
        return cur+1;
        
    }
};

int main(int argc, const char * argv[])
{

//    int A[2] = {1,1};
//    Solution s;
//    cout << s.removeDuplicates(A, 2);
    
    int m = 10;
    int n = 10;
    vector<vector<int>> p(m, vector<int> (n, 0));
    
    int P[m][n];
    
    cout << sizeof(p) << endl;
    cout << sizeof(P) << endl;
    cout << sizeof(int) << endl;
    

    return 0;
}

