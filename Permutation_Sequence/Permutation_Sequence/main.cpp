//
//  main.cpp
//  Permutation_Sequence
//
//  Created by Shuai Wang on 7/2/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
     
        string s(n, '0');
        for(int i=0; i<n; i++){
            s[i] +=i+1;
        }
        
        for(int i=0; i< k; i++){
            nextPermutation(s.begin(), s.end());
            
        }
    }
    
    
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

