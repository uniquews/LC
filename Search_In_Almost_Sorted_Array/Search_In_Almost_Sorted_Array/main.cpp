//
//  main.cpp
//  Search_In_Almost_Sorted_Array
//
//  Created by Shuai Wang on 8/11/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

//
//  main.cpp
//  ttt
//
//  Created by Shuai Wang on 8/11/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution{
public:
    
    // Method 1: hard to deal with duplicate
    
    //    int findElement(int A[], int n, int target){
    //
    //        unordered_map<int, int> pos;
    //
    //        if (n == 0){
    //            return 0;
    //        }
    //
    //        int first = 0;
    //        int end = n -1;
    //
    //        while(first <= end){
    //            int mid = (first + end) / 2;
    //            if (A[mid] == target){
    //                if(pos.find(target) == pos.end())
    //                    return mid;
    //                else{
    //                    return pos[target];
    //                }
    //            }
    //
    //            if(mid == 0 || mid == n -1){
    //                if(A[mid] == target){
    //                    return pos[A[mid]];
    //                }else{
    //                    return -1;
    //                }
    //            }
    //
    //            if (mid >= 1 && A[mid] > A[mid - 1]){
    //                if (mid <= n - 2 && A[mid] < A[mid + 1]){
    //                    // in order
    //                    if (target < A[mid]) {
    //                        end = mid - 1;
    //                    }else{
    //                        first = mid + 1;
    //                    }
    //                }else{
    //                    pos[A[mid]] = mid;
    //                    pos[A[mid + 1]] = mid + 1;
    //                    swap(A[mid], A[mid + 1]);
    //                }
    //
    //            }else{
    //
    //                pos[A[mid]] = mid;
    //                pos[A[mid - 1]] = mid - 1;
    //                swap(A[mid], A[mid - 1]);
    //            }
    //        }
    //
    //        return -1;
    //    }
    
    
    // Method 2: can deal with duplicate.
    
    int findElement(int A[], int n, int target){
        if (n == 0) {
            return -1;
        }
        
        int first = 0;
        int end = n - 1;
        
        while (first <= end) {
            int mid = first + (end - first) / 2;
            if (A[mid] == target) {
                
                int temp = mid;
                
                while (temp > 0 && A[temp - 1] == target) {
                    temp--;
                }
                return temp;
            }
            
            if (mid >= 1 && A[mid - 1] == target) {
                return mid - 1;
            }
            
            if (mid <= n - 2 && A[mid + 1] == target) {
                return mid + 1;
            }
            
            if (A[mid] > target) {
                end = mid - 1;
            }else {
                first = mid + 1;
            }
            
            
        }
        
        return  -1;
    }
};

int main(int argc, const char * argv[])
{
    
    //	TC1:	{10, 3, 40, 20, 50, 80, 70}, key = 40
    //	TC2:	{10, 3, 40, 20, 50, 80, 70}, key = 10
    //	TC3:	{10, 3, 40, 20, 50, 80, 70}, key = 70
    //	TC4:	{3, 10, 40, 20}, key = 20
    //	TC5:	{3, 10}, key = 3
    //	TC6:	{3}, key = 3
    //	TC7:	{10, 3, 40, 20, 50, 80, 70}, key = 5
    //	TC8:	{1, 2, 2, 2, 3}, key = 2
    //	TC9:	{1, 2, 2, 3, 2}, key = 3
    //	TC10:{1, 2, 2, 3, 2, 3}, key = 3
    //	TC11:{}, key = 3;
    
    //    int A[] = {10, 3, 40, 20, 50, 80, 70};
    //    int size = 7;
    
    int A[] = {};
    int size = 0;
    
    Solution su;
    cout << su.findElement(A, size, 3) << endl;
    
    
    
    return 0;
}



int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

