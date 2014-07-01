//
//  main.cpp
//  Search_In_Rotated_Array2
//
//  Created by Shuai Wang on 7/1/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool search(int A[], int n, int target) {
        int start = 0;
        int end = n-1;
        
        
        while(start <= end){
            int mid = (start + end) /2;
            // int midVal = A[mid];
            if(target == A[mid]) return true;
            
            // the left side is in order
            if(A[start] < A[mid]){
                
                if(target >= A[start] && target < A[mid]){
                    end = mid -1;
                }else{
                    start = mid +1;
                }
            }else if(A[start] > A[mid]){
                if(target > A[mid] && target <= A[end]){
                    start = mid +1;
                }else{
                    end = mid-1;
                }
                
            }else{ // A[start] == A[mid] cannot decide which part is in order
                start ++;
            }
            
            
        }
        
        return false;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

