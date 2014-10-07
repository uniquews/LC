//
//  main.cpp
//  Majority_Number3
//
//  Created by Shuai Wang on 9/2/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


//class Solution {
//
//public:
//    
//    int majorityNumber3(vector<int> arr, int k) {
//        unordered_map<int, int> _map;
//        for (auto num : arr) {
//            if (_map.find(num) != _map.end()) {
//                _map[num]++;
//            } else if (_map.size() < k - 1) {
//                _map[num] = 1;
//            } else {
//                for (auto kv : _map) {
//                    kv.second--;
//                }
//            }
//        
//        }
//        
//        
//        for (auto kv : _map) {
//            kv.second = 0;
//        }
//        
//        int count = 0;
//        int candidate = 0;
//        for (auto num : arr) {
//            if (_map.find(num) != _map.end()) {
//                _map[num]++;
//                if (_map[num] > count) {
//                    candidate = _map[num];
//                }
//            
//            }
//        }
//        
//        return candidate;
//    }
//
//};

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        // write your code here
        unordered_map<int, int> hashMap;
        
        for (int i = 0; i < nums.size(); i++) {
            if (hashMap.find(nums[i]) != hashMap.end()) {
                hashMap[nums[i]]++;
            } else if (hashMap.size() < k - 1) {
                hashMap[nums[i]] = 1;
            } else {
                for (auto kv : hashMap) {
                    kv.second--;
                    if (kv.second == 0) {
                        hashMap.erase(kv.first);
                        hashMap[nums[i]]++;
                    }
                }
            }
        }
        
        
        for (auto kv : hashMap) {
            kv.second = 0;
        }
        
        int occur = 0;
        int result = 0;
        for (auto num : nums) {
            if (hashMap.find(num) != hashMap.end()) {
                hashMap[num]++;
                if ( hashMap[num] > occur) {
                    occur =  hashMap[num];
                    result = num;
                }
            }
        }
        
        
        return result;
        
    }
};

int main(int argc, const char * argv[])
{

    vector<int> nums = {32,125,176,234,170,147,151,243,67,62,20,149,191,129,131,107,126,50,194,63,191,191,13,139,191,164,239,119,234,79,51,160,194,140,191,165,80,191,26,26,191,26,16,252,196,12,191,191,249,52,161,169,94,140,250,75,110,143,57,255,90,143,191,71,16,22,50,252,191,138,191,142,221,104,182,57,47,191,179,63,191,68,91,185,225,183,69,216,146,152,164,172,169,68,245,123,191,191,219,207,244,147,215,42,121,112,241,179,27,162,243,133,148,178,214,191,208,138,45,62,191,56,232,74,197,154,225,31,136,191,244,166,41,48,50,94,245,239,103,191,191,161,180,82,210,191,191,253,163,171,140,249,198,51,85,93,55,76,32,191,191,27,57,231,163,205,134,165,40,11,191,133,183,164,138,75,191,22,232,248,54,136,106,109,229,242,121,210,218,28,72,252,90,177,184,60,229,81,98,36,48,21,230,120,19,202,76,196,236,44,162,94,89,151,72,191,242,187,218,228,62,169,62,187,162,232,24,236,164,28,63,117,212,191,206,15,209,85,37,177,23,250,30,126,246,48,115,96,198,106,198,139,19,118,153};
    int k = 9;
    Solution su;
    cout << su.majorityNumber(nums, k) << endl;
    return 0;
}

