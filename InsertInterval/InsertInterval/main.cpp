//
//  main.cpp
//  InsertInterval
//
//  Created by Shuai Wang on 5/29/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Interval{
public:
    int start;
    int end;
    Interval():start(0), end(0){}
    Interval(int start, int end){
        this->start = start;
        this->end  = end;
    }
    
};

//class Solution{
//
//public:
//    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
//        vector<Interval> result;
//        int i=0;
//        int n = intervals.size();
//        while(i<n && newInterval.start > intervals[i].end){
//            result.push_back(intervals[i]);
//            i++;
//        }
//        
//        while(i<n && newInterval.end>=intervals[i].start){ // don't forget equal
//            Interval tempNew;
//            tempNew.start = min(newInterval.start, intervals[i].start);
//            tempNew.end = max(newInterval.end, intervals[i].end);
//            newInterval = tempNew;
//            i++;
//        }
//        
//        result.push_back(newInterval);
//        
//        while(i< n){
//            result.push_back(intervals[i]);
//            i++;
//        }
//        
//        return result;
//        
//    }
//
//};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        if (intervals.size() == 0 ) {
            return vector<Interval> {};
        }
        
        vector<Interval> result;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i].end < newInterval.start) {
                result.push_back(intervals[i]);
            } else if (intervals[i].start > newInterval.end) {
                result.push_back(newInterval);
                result.push_back(intervals[i]);
            } else {
                newInterval.start = min(intervals[i].start, newInterval.start);
                newInterval.end = max(intervals[i].end, newInterval.end);
            }
        }
        
        return result;
    }
};


int main(int argc, const char * argv[])
{

    Interval a(1,5);
    Interval b(6,8);
    vector<Interval> intervals = {a};
    Solution su;
    vector<Interval> result = su.insert(intervals, b);
//    vector<int> A = {1,2,3,4};
//    vector<int> :: iterator it = A.begin();
//    it += 2;
//    A.insert(it, 0);
//    
//    for (int i = 0; i < A.size(); i++) {
//        cout << A[i] << endl;
//    }
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i].start << " " << result[i].end << endl;
    }
    return 0;
}

