//
//  main.cpp
//  Trapping_Rain_Water
//
//  Created by Shuai Wang on 7/2/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;

//class Solution {
//public:
//    int trap(int A[], int n) {
//        int water = 0;
//        int max = 0;
//        
//        
//        //step1: find the tallest one
//        for(int i=0; i< n; i++){
//            if(A[i] > A[max]){
//                max= i;
//                
//            }
//        }
//        
//        // from the left to the tallest one, for each index, how much water it traps
//        for(int i=0, first = 0; i<max; i++){
//            if(A[i] > first)
//                first = A[i];
//            else
//                water += first-A[i];
//        }
//        
//        // from the right to the tallest one, for each index, how much water it traps
//        for(int i=n-1, second = 0; i>=max; i--){
//            if(A[i] > second)
//                second = A[i];
//            else
//                water += second - A[i];
//        }
//        return water;
//    }
//};


class Solution {
public:
    int trap(int A[], int n) {
        int water = 0;
        int tallest = 0;
        
        for (int i = 0; i < n; i++) {
            if (A[i] > A[tallest]) {
                tallest = i;
            }
        }
        
        
        for (int i = 0, left = 0; i < tallest; i++) {
            if (A[i] > left) {
                left = A[i];
            } else {
                water += left - A[i];
            }
        }
        for (int i = n - 1, right = 0; i >= tallest; i--) {
            if (A[i] > right) {
                right = A[i];
            } else {
                water += right - A[i];
            }
        }
        
        return water;
    }
};

int main(int argc, const char * argv[])
{

    int A[] = {4,2,3};
    Solution su;
    cout << su.trap(A, 3) << endl;
    return 0;
}

