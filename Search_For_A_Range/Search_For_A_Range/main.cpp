//
//  main.cpp
//  Search_For_A_Range
//
//  Created by Shuai Wang on 7/14/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>


using namespace std;

//class Solution {
//public:
//    
//    // lazy way
//    vector<int> searchRange(int A[], int n, int target) {
//        int low = distance(A, lower_bound(A, A+n, target));
//        int high = distance(A, prev(upper_bound(A, A+n, target)));
//        
//        if(A[low]!=target){
//            return vector<int>{-1, -1};
//        }else{
//            return vector<int>{low, high};
//        }
//    }
//};

class Solution {
public:
//    vector<int> searchRange(int A[], int n, int target) {
//        auto l = distance(A, lower_bounded(A, A+n, target));
//        auto h = distance(A, upper_bounded(l, A+n, target));
//        
//        if(*l!=target){
//            return vector<int>{-1, -1};
//        }else{
//            return vector<int>{distance(A, l), distance(A, prev(h))};
//        }
//        
//    }
//    
//    
//    template <class ForwardIterator, class T>
//    ForwardIterator lower_bounded(ForwardIterator first, ForwardIterator last, T &value){
//        while(first < last){
//            auto mid = next(first, distance(first, last)/2);
//            if(value >*mid)
//                first = ++mid;
//            else
//                last = mid;
//        }
//        
//        return first;
//    }
//    
////    template <class ForwardIterator, class T>
////    ForwardIterator lower_bounded(ForwardIterator first, ForwardIterator last, T &value){
////        while(first < last){
////            auto mid = (first + last) /2;
////            if(value >*mid)
////                first = ++mid;
////            else
////                last = mid;
////        }
////        
////        return first;
////    }
//    
//    template <class ForwardIterator, class T>
//    ForwardIterator upper_bounded(ForwardIterator first, ForwardIterator last, T &value){
//        while(first < last){
//            auto mid = next(first, distance(first, last)/2);
//            if(value >=*mid)
//                first = ++mid;
//            else
//                last = mid;
//        }
//        
//        return first;
//    }
    
};


class exls{
public:
    template <class ForwardIterator, class T>
    ForwardIterator lower_bounded(ForwardIterator first, ForwardIterator last, T &value){
        while(first < last){
            auto mid = (first + last) /2;
            if(value >*mid)
                first = ++mid;
            else
                last = mid;
        }
        
        return first;
    }


};



int main(int argc, const char * argv[])
{

    int A[] = {1,1,1,2,3,3,4,4,4,5};
    exls ex;
    cout << distance (A, ex.lower_bounded(A, A+10, 1));
    
    
    
    return 0;
}

