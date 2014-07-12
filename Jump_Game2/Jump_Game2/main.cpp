//
//  main.cpp
//  Jump_Game2
//
//  Created by Shuai Wang on 7/12/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
        int left = 0;
        int right = 0;
        int step = 0;
        if(n == 1) return 0; // !!!!
        while(left <= right){
            step++;
            int oldRight = right;
            for(int i = left; i<= oldRight; i++){
                int temp = i + A[i];
                if(temp >= n-1) return step;
                if(temp > right) right = temp; //!!!
                
            }
            
            left = oldRight+1;
        }
        
        return 0;
    }
    
};

int main(int argc, const char * argv[])
{

    int A[] = {1, 2};
    Solution su;
    cout << su.jump(A, 2);
    return 0;
}

