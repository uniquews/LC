//
//  main.cpp
//  Single_Number_III
//
//  Created by Shuai Wang on 8/31/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//
//public:
//    vector<int> singleNumber3(int A[], int n) {
//        vector<int> result;
//        int tmp = A[0] ^ A[1];
//        
//        for (int i = 2; i < n; i++) {
//            tmp = tmp ^ A[i];
//        }
//        
//        vector<int> A1;
//        
//        vector<int> A2;
//        
//        for (int i = 0; i < 32; i++) {
//            
//            if (((tmp >> i) & 1) == 1) {
//                for (int j = 0; j < n; j++) {
//                    if (((A[j] >> i) & 1) == 1) {
//                        A1.push_back(A[j]);
//                    } else {
//                        A2.push_back(A[j]);
//                    }
//                }
//                break;
//            }
//        }
//        
//        int temp = 0;
//        for (int i = 0; i < A1.size(); i++) {
//            temp = temp ^ A1[i];
//        }
//        result.push_back(temp);
//        
//        
//        int temp2 = 0;
//        for (int i = 0; i < A2.size(); i++) {
//            temp2 = temp2 ^ A2[i];
//        }
//        result.push_back(temp2);
//        
//        return result;
//    }
//
//
//};


class Solution {
public:
    
    vector<int> singleNumber3(vector<int> &num) {
        if (num.size() == 0) {
            return vector<int> {};
        }
        
        vector<int> result;
        
        int xorResult = 0;
        int diff = -1;
        
        vector<int> first;
        vector<int> second;
        
        for (int i = 0; i < num.size(); i++) {
            xorResult = xorResult ^ num[i];
        }
        
        for (int i = 0; i < 32; i++) {
            int tmp = (xorResult >> i) & 1;
            if (tmp == 1) {
                diff = i;
            }
        }
        
        
        for (int i = 0; i < num.size(); i++) {
            int tmp = (num[i] >> diff) & 1;
            if (tmp == 0) {
                first.push_back(num[i]);
            } else {
                second.push_back(num[i]);
            }
            
        }
        
        int firstResult = 0;
        for (int i = 0; i < first.size(); i++) {
            firstResult = firstResult ^ first[i];
        }
        
        int secondResult = 0;
        for (int i = 0; i < second.size(); i++) {
            secondResult = secondResult ^ second[i];
        }
        
        result.push_back(firstResult);
        result.push_back(secondResult);
        return result;
        
    }
    
    
};

int main(int argc, const char * argv[])
{

    vector<int> A = {2,2,3,4,3,4,5,6,6,5,7,8};
    Solution su;
    vector<int> result = su.singleNumber3(A);
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    
    
    cout << endl;
    return 0;
}

