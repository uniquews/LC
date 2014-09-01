//
//  main.cpp
//  Majority_Number2
//
//  Created by Shuai Wang on 8/31/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {

public:
    int majorityNumber2 (int A[], int n) {
        int candidate1 = 0;
        int count1 = 0;
        int candidate2 = 0;
        int count2 = 0;
        
        for (int i = 0; i < n; i++) {
            if (count1 == 0) {
                candidate1 = A[i];
                count1++;
            } else if (count2 == 0 && candidate1 != A[i]){
                candidate2 = A[i];
                count2++;
            } else if (candidate1 == A[i]) {
                count1++;
            } else if (candidate2 == A[i]) {
                count2++;
            } else {
                count1--;
                count2--;
            }
        
        }
        
        
        count1 = 0;
        count2 = 0;
        
        for (int i = 0; i < n; i++) {
            if (A[i] == candidate1) {
                count1++;
            } else if (A[i] == candidate2) {
                count2++;
            }
        }
        
        if (count1 > count2) {
            return candidate1;
        } else {
            return candidate2;
        }
    
    }

};

int main(int argc, const char * argv[])
{

    int A[] = {1,2,1,2,1,1,1,3};
    Solution su;
    cout << su.majorityNumber2(A, 9) << endl;
    return 0;
}

