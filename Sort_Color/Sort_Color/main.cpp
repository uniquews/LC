//
//  main.cpp
//  Sort_Color
//
//  Created by Shuai Wang on 7/14/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;


class Solution {
public:
    void sortColors(int A[], int n) {
        quicksort(A, 0, n - 1);
        return;
    }
    
    void quicksort(int A[], int start, int end) {
        if (start < end) {
            int index = partition(A, start, end);
            quicksort(A, start, index - 1);
            quicksort(A, index + 1, end);
        }
        return;
    }
    
    int partition(int A[], int start, int end) {
        int pivot = A[end];
        int leftTail = start - 1;
        for (int rightHead = start; rightHead <= end - 1; rightHead++) {
            if (A[rightHead] <= pivot) {
                leftTail++;
                swap(A[leftTail], A[rightHead]);
            }
        }
        
        swap(A[leftTail + 1], A[end]);
        return leftTail + 1;
        
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

