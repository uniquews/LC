//
//  main.cpp
//  MergeTwoSortedArray
//
//  Created by Shuai Wang on 3/28/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution{
public:
    static void merge(int A[], int m, int B[], int n){
        //resize the A
        int a=m-1;
        int b=n-1;
        int cur = m+n-1;
        
        while(a>=0 && b>=0){
            A[cur--]=A[a]>B[b]?A[a--]:B[b--];  // wrong: A[j--] = B[j--]. minus j twice. A[j] = B[j--] correct
        }
        
        while(b>=0){
            A[cur--]=B[b--];
        }
        return;
    }

};

int main(int argc, const char * argv[])
{

    // insert code here...
    int A[100]={1,2,8,11,45};
    int B[4]={5,6,66,100};
//    int B[0];
    Solution:: merge(A, 5, B, 4);
    for(int i=0; i<9; i++){
        cout<< A[i]<<endl;
    }
    std::cout << "Hello, World!\n";
    return 0;
}

