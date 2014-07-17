//
//  main.cpp
//  Insert_Sort
//
//  Created by Shuai Wang on 7/14/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//


//Insertion sort is stable sorting alg.

#include <iostream>

using namespace std;

class Insert_Sort{

public:
    
    void sortAlg(int A[], int n){
        for(int i=0; i<n; i++){
            int temp = A[i];
            int j = i;
            while(j>0 && A[j-1]> temp){
                A[j]  =A[j-1];
                j--;
            }
            
            A[j] = temp;
        }
    
    }

};

int main(int argc, const char * argv[])
{

    int A[] = {5,1,2,3,4};
    
    Insert_Sort su;
    su.sortAlg(A, 5);
    
    for(int i=0; i< 5; i++){
        
        cout << A[i] << " ";
        
        
    }
    
    cout << endl;
    return 0;
}

