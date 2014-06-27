//
//  main.cpp
//  Search_In_Rotated_Array
//
//  Created by Shuai Wang on 6/26/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//


#include <iostream>

using namespace std;


class Solution {
public:
    int search(int A[], int n, int target) {
        int first = 0;
        int last = n-1;
        
        while(first <=last){
            int mid = (first + last) /2;
            int midNum = A[mid];
            if(midNum == target)
                return mid;
            if(A[first] <= A[mid]){
                if(A[first] <= target && target < A[mid]){
                    last = mid-1;
                    
                }else{
                    first = mid +1;
                    
                }
                
            }else{
                if(A[mid]<target && target <= A[last]){
                    first = mid+1;
                }else{
                    last = mid-1;
                }
                
            }
            
        }
        
        return -1;
    }
};


int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

