//
//  main.cpp
//  Bubble_Sort
//
//  Created by Shuai Wang on 7/14/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//



// Bubble sort is stable sorting alg.

#include <iostream>

using namespace std;

class BubbleSort{

public:
    
    void sortAlg(int A[], int n){
        for(int i = n-1; i>=0; i--){ //  the end
            for(int j = 1; j <=i; j++){
                if(A[j] < A[j-1])
                    swap(A[j], A[j-1]);
            }
        }
    
    }

};

int main(int argc, const char * argv[])
{

    int A[] = {5,1,2,3,4};
    BubbleSort bu;
    bu.sortAlg(A, 5);
    
    for(int i=0; i< 5; i++){
    
        cout << A[i] << " ";
        
        
    }
    
    cout << endl;
    return 0;
}

