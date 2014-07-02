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

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        if(num.size() == 0) return;
        int largestPartitonNumIndex = -1;
        int largestChangeNumIndex = -1;
        
        //step 1
        for(size_t i =0; i< num.size()-1; i++){
            if(num[i] < num[i+1])
                largestPartitonNumIndex = i;
        }
        
        if(largestPartitonNumIndex == -1) // already be the largest permutation
            return sort(num.begin(), num.end());
        
        //step 2
        for(size_t i=0; i<num.size(); i++){
            if(num[i] > num[largestPartitonNumIndex])
                largestChangeNumIndex  = i;
        }
        
        swap(num[largestChangeNumIndex], num[largestPartitonNumIndex]);
        
        reverse(num.begin()+largestPartitonNumIndex+1, num.end());
        return;
        
        
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

