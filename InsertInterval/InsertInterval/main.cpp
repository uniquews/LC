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
    Interval():start(0). end(0){}
    Interval(int start, int end){
        this->start = start;
        this->end  = end;
    }
    
};

class Solution{

public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;
        int i=0;
        int n = intervals.size();
        while(i<n && newInterval.start > intervals[i].end){
            result.push_back(intervals[i]);
            i++;
        }
        
        while(i<n && newInterval.end>=intervals[i].start){ // don't forget equal
            Interval tempNew;
            tempNew.start = min(newInterval.start, intervals[i].start);
            tempNew.end = max(newInterval.end, intervals[i].end);
            newInterval = tempNew;
            i++;
        }
        
        result.push_back(newInterval);
        
        while(i< n){
            result.push_back(intervals[i]);
            i++;
        }
        
        return result;
        
    }

};


int main(int argc, const char * argv[])
{

    // insert code here...
    return 0;
}

