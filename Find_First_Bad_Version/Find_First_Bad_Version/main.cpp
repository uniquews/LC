//
//  main.cpp
//  Find_First_Bad_Version
//
//  Created by Shuai Wang on 8/14/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    
    int findFirstBad(vector<int> &nums) {
        if (nums.size() == 0) {
            return -1;
        }
        
        int first = 0;
        int last = (int) nums.size() - 1;
        
        while (first + 1 < last) {
            int mid  = first + (last - first) / 2;
            if (isBadVersion (nums[mid]) == true) {
                last = mid;
            } else {
                first = mid;
            }
        
        }
        
        // The return is index
        
        if (isBadVersion (nums[first])) {
            return first;
        }
        
        if (isBadVersion (nums[last])) {
            return last;
        }
        
        return -1; // no bad version
    }
    
    
    bool isBadVersion (int version) {
        vector<int> badVersions = {6,7,8};
        vector<int> ::iterator it = badVersions.begin();
        for (; it != badVersions.end(); it++) {
            if (*it == version) {
                return true;
            }
        }
        return false;
    }
    

};



int main(int argc, const char * argv[])
{

    Solution su;
    vector<int> arr = {1,2,3,4,5,6,7,8};
    cout << su.findFirstBad(arr) << endl;
    
//    if (find(arr.begin(), arr.end(), 4) != arr.end()) {
//        cout << true << endl;
//    } else {
//        cout << false <<endl;
//    }
    
    
    
    return 0;
}

