//
//  main.cpp
//  Sort_Color
//
//  Created by Shuai Wang on 7/14/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;

//class Solution {
//public:
//    void sortColors(int A[], int n) {
//        int red = 0; // from left to right, the first one is not red
//        int blue = n-1; // from right to left, the first one is not blue
//        
//        for(int i=0; i<=blue;){
//            if(A[i] == 0){
//                swap(A[i++], A[red++]);
//            }else if(A[i] == 2){
//                swap(A[i], A[blue--]);
//            }else{
//                i++;
//            }
//        }
//        
//        return;
//    }
//};

class Solution {
public:
    void sortColors(int A[], int n) {
        if (n == 0) {
            return;
        }
        
        int start = 0;
        int end = n - 1;
        while (start <= end) {
            while (A[start] == 0) {
                start++;
            }
            
            while(A[end] == 1 || A[end] ==2) {
                end--;
            }
            
            if (start <= end) {
                int tmp = A[start];
                A[start] = A[end];
                A[end] = tmp;
                start++;
                end--;
            }
        }
        
        start = start;
        end = n - 1;
        while (start <= end) {
            while (A[start] == 1) {
                start++;
            }
            
            while (A[end] == 2) {
                end--;
            }
            
            if (start <= end) {
                int tmp = A[start];
                A[start] = A[end];
                A[end] = tmp;
                start++;
                end--;
            }
        }
        
        return;
    }
};

int main(int argc, const char * argv[])
{

    int  A[] = {0,0,2,2,2,1,1,1,1};
    int n = 9;
    Solution su;
    su.sortColors(A, n);
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    
    cout << endl;
    return 0;
}

