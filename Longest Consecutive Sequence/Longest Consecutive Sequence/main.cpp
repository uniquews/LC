//
//  main.cpp
//  Longest Consecutive Sequence
//
//  Created by Shuai Wang on 9/17/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>

using namespace std;


//class Solution {
//public:
//    int longestConsecutive(vector<int> &num) {
//        if (num.size() == 0) {
//            return 0;
//        }
//        
//        int result = 1;
//        unordered_set<int> hashSet;
//        
//        for (int i = 0; i < num.size(); i++) {
//            hashSet.insert(num[i]);
//        }
//        
//        for (int i = 0; i < num.size(); i++) {
//            
//            if (hashSet.find(num[i]) == hashSet.end()) {
//                continue;
//            }
//            
//            int len = 1;
//            
//            hashSet.erase(num[i]);
//            int increase = num[i] + 1;
//            int decrease = num[i] - 1;
//            
//            while (hashSet.find(increase) != hashSet.end()) {
//                hashSet.erase(increase);
//                len++;
//                increase++;
//            }
//            
//            while (hashSet.find(decrease) != hashSet.end()) {
//                hashSet.erase(decrease);
//                len++;
//                decrease--;
//            }
//            
//            result = max(result, len);
//        }
//        
//        return result;
//    }
//};

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if (num.size() == 0) {
            return 0;
        }
        
        unordered_set<int> hashSet;
        for (auto i : num) {
            hashSet.insert(i);
        }
        
        int result = 1;
        
        for (int i = 0; i < num.size(); i++) {
            if (hashSet.find(num[i]) == hashSet.end()) {
                continue;
            }
            
            int len = 1;
            hashSet.erase(num[i]);
            int increase = num[i] + 1;
            int decrease = num[i] - 1;
            while (hashSet.find(increase) != hashSet.end()) {
                len++;
                hashSet.erase(increase);
                increase++;
            }
            
            while (hashSet.find(decrease) != hashSet.end()) {
                len++;
                hashSet.erase(decrease);
                decrease--;
            }
            
            result = max(result, len);
        }
        return result;
    }
};

int main(int argc, const char * argv[])
{

//    vector<int> num = {9000,8999,8998,8997,8996,8995,8994,8993,8992,8991,8990,8989,8988,8987,8986,8985,8984,8983,8982,8981,8980,8979,8978,8977,8976,8975,8974,8973,8972,8971,8970,8969,8968,8967,8966,8965,8964,8963,8962,8961,8960,8959,8958,8957,8956,8955,8954,8953,8952,8951,8950,8949,8948,8947,8946,8945,8944,8943,8942,8941,8940,8939,8938,8937,8936,8935,8934,8933,8932,8931,8930,8929,8928,8927,8926,8925,8924,8923,8922,8921,8920,8919,8918,8917,8916,8915,8914,8913,8912,8911,8910,8909,8908,8907,8906,8905,8904,8903,8902,8901,8900,8899,8898,8897,8896,8895,8894,8893,8892,8891,8890,8889,8888,8887,8886,8885,8884,8883,8882,8881,8880,8879,8878,8877,8876,8875,8874,8873,8872,8871,8870,8869,8868,8867,8866,8865,8864,8863,8862,8861,8860,8859,8858,8857,8856,8855,8854,8853,8852,8851};
    
//    vector<int> num = {10,9,8,7,6,5,4,3,2,1};
    vector<int> num = {100, 4, 200, 1, 3, 2};

    Solution su;
    cout << su.longestConsecutive(num) <<endl;
    return 0;
}

