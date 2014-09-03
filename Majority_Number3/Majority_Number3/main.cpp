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


class Solution {

public:
    
    int majorityNumber3(vector<int> arr, int k) {
        unordered_map<int, int> _map;
        for (auto num : arr) {
            if (_map.find(num) != _map.end()) {
                _map[num]++;
            } else if (_map.size() < k - 1) {
                _map[num] = 1;
            } else {
                for (auto kv : _map) {
                    kv.second--;
                }
            }
        
        }
        
        
        for (auto kv : _map) {
            kv.second = 0;
        }
        
        int count = 0;
        int candidate = 0;
        for (auto num : arr) {
            if (_map.find(num) != _map.end()) {
                _map[num]++;
                if (_map[num] > count) {
                    candidate = _map[num];
                }
            
            }
        }
        
        return candidate;
    }

};

int main(int argc, const char * argv[])
{


    return 0;
}

