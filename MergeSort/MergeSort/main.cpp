//
//  main.cpp
//  MergeSort
//
//  Created by Shuai Wang on 3/31/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    static void mergesort(vector<int> &arr){
        //vector<int> *helper = new vector<int> (arr.size());
        //or just
        vector<int> helper (arr.size());
        
        mergesort(helper, arr, 0, (int)arr.size()-1);
        return;
    }
    
    
    static void mergesort(vector<int> &helper, vector<int> &arr, int left, int right){
        if(left<right){
            int middle = (left+right)/2;
            mergesort(helper, arr, left, middle);
            mergesort(helper, arr, middle+1, right);
            merge(helper, arr, left, middle, right);
            return;
        }
        
    }
    
    static void merge(vector<int> &helper, vector<int> &arr, int left, int middle, int right){
        for(int i=left; i<=right;i++){
            helper[i]=arr[i];
        }
        
        int leftSideBegin = left;
        int rightSideBegin = middle+1;
        int current=left;
        
        while (leftSideBegin<=middle && rightSideBegin <=right) {
            if(helper[leftSideBegin]<helper[rightSideBegin]){//The left side element is smaller than the right side element
                arr[current]=helper[leftSideBegin];
                leftSideBegin++;
            }else{// The right side element is smaller or equal to the left side element
                arr[current]=helper[rightSideBegin];
                rightSideBegin++;
            }
            current++;
        }
        
        int remaining = middle-leftSideBegin;
            for(int i=0; i<=remaining;i++){
                arr[current+i] = helper[leftSideBegin+i];
        }
        return;
    }
};


int main(int argc, const char * argv[])
{

    // insert code here...
    vector<int> a={2,1,4,3,5,2,5,6,2};
    Solution::mergesort(a);
    vector<int>::iterator it=a.begin();
    for(;it!=a.end();it++){
        cout<<*it<<" ";
    }
    return 0;
}

