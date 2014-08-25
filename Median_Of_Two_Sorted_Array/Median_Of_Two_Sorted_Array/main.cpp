//
//  main.cpp
//  Median_Of_Two_Sorted_Array
//
//  Created by Shuai Wang on 7/1/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int sum = m + n;
        if(sum & 0x1){ // if sum is odd, the median shoule be only one number
            return findKthNumber(A, m, B, n, sum/2+1);
        }else{
            return (findKthNumber(A, m, B, n, sum/2+1) + // nth, not the index
                    findKthNumber(A, m, B, n, sum/2))/2;
        }
    }
    
    
    double findKthNumber(int A[], int m, int B[], int n, int k){
        if(m > n){
            return findKthNumber(B, n, A, m, k);  // For convenience, we always make array A as the smaller size array
        }
        
        if(m==0) //edge case
            return B[k-1];
        
        if(k == 1) // edge case
            return min(A[0], B[0]);
        
        int pos = min(k/2, m);  // need to remember
        int posInB = k-pos;
        
        if(A[pos-1] < B[posInB-1]){ // nth to index, code should minus 1
            return findKthNumber(A+pos, m-pos, B, n, k-pos); // median cannot be in the first part of A
        }else if(A[pos-1] > B[posInB-1]){
            return findKthNumber(A, m, B+posInB, n-posInB, k-posInB); // median cannot be in the first part of B
        }else{
            return A[pos-1]; 
        }
        
    }
    
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

