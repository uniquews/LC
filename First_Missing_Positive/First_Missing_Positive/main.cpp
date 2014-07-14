//
//  main.cpp
//  First_Missing_Positive
//
//  Created by Shuai Wang on 7/14/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        sortAlg(A, 4);
        
        for(int i = 0; i< n; i++){
            cout << A[i] << " ";
            
        }
        cout << endl;
        for(int i =0; i< n; i++){
            if(A[i]!=i+1)
                return i+1;
        }
        return n+1;
    }
    
//    void sortAlg(int A[], int n){
//        for(int i =0; i<n; i++){
//            if(A[i] <0 || A[i] > n-1 || A[i] == A[A[i]-1]){
//                //
//                continue;
//            }else{
//                swap(A[i], A[A[i]-1]);
//            }
//        }
//        
//        return;
//    }
    
    void sortAlg(int A[], int n){
        for(int i=0; i<n; i++){
            while(A[i]!=i+1){
                if(A[i]<=0 ||  A[i]>n || A[i]==A[A[i]-1]){ //无须交换
                    break;
                }
                swap(A[i], A[A[i]-1]); //把A[i]放到正确的地方  i是不能改变的  所以A[i]=i+1不能变，只能把A[i]移到A[A[i]-1]
            }
        }
        
        return;
    }
};


int main(int argc, const char * argv[])
{

    int A[] = {-1, 4, 3, 1};
    Solution su;
    su.firstMissingPositive(A, 4);
    return 0;
}

