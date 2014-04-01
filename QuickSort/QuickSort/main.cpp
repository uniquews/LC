//
//  main.cpp
//  QuickSort
//
//  Created by Shuai Wang on 3/31/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    static  void quickSort(vector<int> &arr, int left, int right){
        int index = partition(arr, left, right);
        if(left<index-1){ //[start, end]?
            quickSort(arr,left,index-1);
            
            if(index<right){
                quickSort(arr, index, right);
            }
        }
    }
    
    static int partition (vector<int> &arr, int left, int right){
        int pivot = arr[(left+right)/2];
        while(left<=right){
            while(arr[left]<pivot) left++;
            while(arr[right]>pivot) right--;
            if(left<=right){
                swap(arr, left, right);
                left++;
                right--;
            }
        }
        return left;
    }
    
    static void swap(vector<int> &arr, int left, int right){
        int temp = arr[left];
        arr[left]=arr[right];
        arr[right]=temp;
        return;
    }
};


int main(int argc, const char * argv[])
{

    cout<<"hhhh"<<endl;
    // insert code here...
//    int a[]={1,2,3,4,5};
    vector<int> a={1,2,3,4,5,4,2};
    int end = (int)a.size();

    
    Solution::quickSort(a, 0, end-1);
    
    for(int i=0;i<end;i++){
        cout << a[i]<<" ";
    }
    return 0;
}

