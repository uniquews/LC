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
     
        vector<int> nums(n);
        int permCount =1;
        for(int i =0; i< n; i++)
        {
            nums[i] = i+1;
            permCount *= (i+1);
        }
        // change K from (1,n) to (0, n-1) to accord to index
        k--;
        string targetNum;
        for(int i =0; i< n; i++)
        {
            permCount = permCount/ (n-i);
            int choosed = k / permCount;
            targetNum.push_back(nums[choosed] + '0');
            //restruct nums since one num has been picked
            for(int j =choosed; j< n-i; j++)
            {
                cout << nums[j] << " " << nums[j + 1];
                nums[j]=nums[j+1];
            }
            k = k%permCount;
        }
        return targetNum;
    }
    
    

};



int main(int argc, const char * argv[])
{

    int n = 3;
    int k = 6;
    Solution su;
    cout << su.getPermutation(n, k) <<endl;
    return 0;
}

