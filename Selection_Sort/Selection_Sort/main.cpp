//
//  main.cpp
//  Selection_Sort
//
//  Created by Shuai Wang on 7/14/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//


//not stable why?
//http://stackoverflow.com/questions/20761396/why-selection-sort-can-be-stable-or-unstable


#include <iostream>

using namespace std;

class Selection_Sort{

public:
    
    void sortAlg(int A[], int n){
        for(int i =0; i<n-1; i++){
            int minIndex = i;
            for(int j = i+1; j< n; j++){
                if(A[minIndex] > A[j])
                    swap(A[minIndex], A[j]);
            }
        
        }
    }

};

int main(int argc, const char * argv[])
{

    int A[] = {5,1,2,3,2,4};
    Selection_Sort su;
    su.sortAlg(A, 5);
    
    for (int i=0; i< 5; i++){
        cout << A[i] <<" ";
    }
    
    cout << endl;
    return 0;
}

