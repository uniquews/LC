//
//  main.cpp
//  Search_Insert_Position
//
//  Created by Shuai Wang on 7/14/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        return distance(A, lower_bound(A, A+n, target));
    }
    
    template <typename ForwardIterator, typename T>
    ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, T &value){
        
        while(first != last){
            auto mid = next(first, distance(first, last)/2);
            if(value > *mid) first = ++mid;
            else last = mid;
        }
        
        return first;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

