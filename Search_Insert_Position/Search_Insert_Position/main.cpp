//
//  main.cpp
//  Search_Insert_Position
//
//  Created by Shuai Wang on 7/14/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if (n == 0){
            return 0;
        }
        
        int first = 0;
        int end = n - 1;
        int mid = (first + end) / 2;
        
        while(first <= end){
            mid = (first + end) / 2;
            if (A[mid] == target){
                return mid;
            }else if (A[mid] < target){
                first = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        
        if (A[mid] < target){
            return mid + 1;
        }
        
        if (A[mid] > target){
            return mid;
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

