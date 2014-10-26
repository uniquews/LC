//
//  main.cpp
//  Next_Permutation
//
//  Created by Shuai Wang on 7/2/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//



//Step 1: Find the largest index k, such that A[k]<A[k+1]. If not exist, this is the last permutation. (in this    problem just sort the vector and return.)
//Step 2: Find the largest index l, such that A[l]>A[k].
//Step 3: Swap A[k] and A[l].
//Step 4: Reverse A[k+1] to the end.



#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    void nextPermutation(vector<int> &num) {
//        if (num.size() <= 1) {
//            return;
//        }
//        
//        int start = (int)num.size() - 2;
//        while (start >= 0) {
//            if (num[start] < num[start + 1]) {
//                break;
//            }
//            
//            start--;
//        }
//        
//        if (start == -1) {
//            sort(num.begin(), num.end());
//            return;
//        }
//        
//        int end = (int)num.size() - 1;
//        int index = 0;
//        int find = INT_MAX;
//        while (end > start) {
//            if (num[end] > num[start] && num[end] < find) {
//                index = end;
//                find = num[index];
//            }
//            
//            end--;
//        }
//        
//        swap(num[start], num[index]);
//        
//        vector<int> :: iterator it = num.begin();
//        reverse(it + start + 1, num.end());
//        return;
//    }
//};

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if (num.size() <= 1) {
            return;
        }
        
        int start = (int)num.size() - 1;
        while (start - 1 >= 0 && num[start - 1] > num[start]) {
            start--;
        }
        
        if (start == 0) {
            reverse(num.begin(), num.end());
            return;
        }
        
        start--;
        int end = (int)num.size() - 1;
        while (num[end] <= num[start]) {
            end--;
        }
        
        swap(num[start], num[end]);
        vector<int> :: iterator it = num.begin();
        it = it + start + 1;
        reverse(it, num.end());
        return;
        
    }
};

int main(int argc, const char * argv[])
{

    vector<int> num = {1,2,3};
    Solution su;
    su.nextPermutation(num);
    for (int i = 0; i < num.size(); i++) {
        cout << num[i] << endl;
    }
    return 0;
}

