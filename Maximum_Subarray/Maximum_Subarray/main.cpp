//
//  main.cpp
//  Maximum_Subarray
//
//  Created by Shuai Wang on 6/25/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n == 0) return 0;
        int maxVal =INT_MIN;
        vector<int> tempMax (n, INT_MIN);
        tempMax[0] =A[0];
        
        for(int i=1; i<n; i++){
            tempMax[i] = std::max(tempMax[i-1]+ A[i], A[i]);
            if(tempMax[i] > maxVal)
                maxVal = tempMax[i];
        }
        
        return maxVal;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    int A[9] = {-2 ,1, -3, 4, -1, 2, 1, -5, 4};
    Solution s;
    cout << s.maxSubArray(A, 9) << endl;
    
    return 0;
}

