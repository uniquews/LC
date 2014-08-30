//
//  main.cpp
//  Jump_Game2
//
//  Created by Shuai Wang on 7/12/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    int jump(int A[], int n) {
//        int left = 0;
//        int right = 0;
//        int step = 0;
//        if(n == 1) return 0; // !!!!
//        while(left <= right){
//            step++;
//            int oldRight = right;
//            for(int i = left; i<= oldRight; i++){
//                int temp = i + A[i];
//                if(temp >= n-1) return step;
//                if(temp > right) right = temp; //!!!
//                
//            }
//            
//            left = oldRight+1;
//        }
//        
//        return 0;
//    }
//    
//};

class Solution {
public:
    int jump(int A[], int n) {
        if (n <= 1) {
            return n;
        }
        vector<int> table(n, INT_MAX);
        table[0] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (table[j] + A[j] >= i) {
                    table[i] = min(table[i], table[j] + 1);
                } else {
                    continue;
                }
                
            }
        }
        
        if (table[n - 1] == INT_MAX) {
            return -1;
        } else {
            return table[n - 1];
        }
    }
};

int main(int argc, const char * argv[])
{

    int A[] = {1, 2};
    Solution su;
    cout << su.jump(A, 2) << endl;
    return 0;
}

