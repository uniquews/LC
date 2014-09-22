//
//  main.cpp
//  3Sum
//
//  Created by Shuai Wang on 3/29/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        if (num.size() == 0) {
            return vector<vector<int>> {};
        }
        
        sort(num.begin(), num.end());
        vector<vector<int>> result;
        for (int i = 0; i < (int)num.size() - 2; i++) {
            int tempGap = 0 - num[i];
            int start = i + 1;
            int end = (int)num.size() - 1;
            while (start < end) {
                if (num[start] + num[end] == tempGap) {
                    vector<int> eachResult;
                    eachResult.push_back(num[i]);
                    eachResult.push_back(num[start]);
                    eachResult.push_back(num[end]);
                    result.push_back(eachResult);
                    
                    while (start + 1 < end && num[start] == num[start + 1]) {
                        start++;
                    }
                    
                    while (end - 1 > start && num[end] == num[end - 1]) {
                        end--;
                    }
                    
                    start++;
                    end--;
                } else if (num[start] + num[end] > tempGap) {
                    end--;
                } else {
                    start++;
                }
            }
            
            while (i + 1 < num.size() - 2 && num[i + 1] == num[i]) {
                i++;
            }
        }
        
        return result;
    }
};


//-4 -1 -1 0 1 2



int main(int argc, const char * argv[])
{
    

    // insert code here...
    vector<int> num = {-1, 0, 1, 2, -1, -4};
    vector<int> temp;
//    vector<int> num = {0};
    Solution su;
   vector<vector<int>> result = su.threeSum(num);
    for(vector<vector<int>>::iterator it=result.begin(); it<result.end();it++){
        temp = *it;
        for(vector<int>::iterator it2 = temp.begin(); it2<temp.end();it2++){
            cout<< *it2<<" ";
        }
        cout<<endl;
    }
    return 0;
}

