//
//  main.cpp
//  Search_In_Rotated_Array
//
//  Created by Shuai Wang on 6/26/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//


#include <iostream>

using namespace std;


//class Solution {
//public:
//    int search(int A[], int n, int target) {
//        int first = 0;
//        int last = n-1;
//        
//        while(first <=last){
//            int mid = (first + last) /2;
//            int midNum = A[mid];
//            if(midNum == target)
//                return mid;
//            if(A[first] <= A[mid]){
//                if(A[first] <= target && target < A[mid]){
//                    last = mid-1;
//                    
//                }else{
//                    first = mid +1;
//                    
//                }
//                
//            }else{
//                if(A[mid]<target && target <= A[last]){
//                    first = mid+1;
//                }else{
//                    last = mid-1;
//                }
//                
//            }
//            
//        }
//        
//        return -1;
//    }
//};

class Solution {
public:
    int search(int A[], int n, int target) {
		int start = 0;
		int end = n - 1;
        
		while (start + 1 < end) {
			int mid = start + (end - start) / 2;
			if (A[mid] == target) {
				return mid;
			} else if (A[start] < A[mid]) {
			    if (A[start] <= target && target < A[mid]) {
			        end = mid;
			    } else {
			        start = mid;
			    }
			} else {
			    if (A[mid] < target && target <= A[end]) {
			        start = mid;
			    } else {
			        end = mid;
			    }
			}
            
		}
        
		if (A[start] == target) {
			return start;
		}
        
		if (A[end] == target) {
			return end;
		}
        
		return -1;
    }
};


int main(int argc, const char * argv[])
{

    int A[] = {4,5,6,7,8,1,2,3};
    int target = 8;
    Solution su;
    cout << su.search(A, 8, 8) << endl;
    
    return 0;
}

