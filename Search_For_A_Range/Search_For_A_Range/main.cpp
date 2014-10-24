//
//  main.cpp
//  Search_For_A_Range
//
//  Created by Shuai Wang on 7/14/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        if (n == 0) {
            return vector<int> {-1, -1};
        }
        
        vector<int> result;
        int start = 0;
        int end = n - 1;

        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] == target) {
                end = mid;
            } else if (A[mid] > target) {
                end = mid;
            } else {
                start = mid;
            }
        }
        
        if (A[start] == target) {
            result.push_back(start);
        } else if (A[end] == target) {
            result.push_back(end);
        } else {
            result.push_back(-1);
        }
        
        
        start = 0;
        end = n - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (A[mid] == target) {
                start = mid;
            } else if (A[mid] > target) {
                end = mid;
            } else {
                start = mid;
            }
        }
        
        if (A[end] == target) {
            result.push_back(end);
        } else if (A[start] == target) {
            result.push_back(start);
        } else {
            result.push_back(-1);
        }
        
        return result;
    }
};


int main(int argc, const char * argv[])
{
  
    int A[] = {5, 7, 7, 8, 8, 10};
    Solution su;
    vector<int> result = su.searchRange(A, 6, 8);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}

