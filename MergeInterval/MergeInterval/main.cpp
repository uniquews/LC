//
//  main.cpp
//  MergeInterval
//
//  Created by Shuai Wang on 5/30/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

 struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Comp{
public:
    bool operator()(const Interval &i1, const Interval &i2){
        return i1.start < i2.start;
    }
};

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        sort(intervals.begin(), intervals.end(), Comp());
        
        vector<Interval> result;
        int i=0;
        int n = intervals.size();
        while(i<n){
            result.push_back(intervals[i++]);
            while(i<n && result.back().end >= intervals[i].start){
                Interval temp = result.back();
                temp.end = max(intervals[i].end, temp.end);
                result.back() = temp;
                i++;
            }
            
        }
        
        return result;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

