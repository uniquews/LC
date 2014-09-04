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

class Solution{
public:
    
        vector<vector<int> > threeSum(vector<int> &num) {
            if (num.size() == 0) {
                return vector<vector<int>> {};
            }
            
            sort(num.begin(), num.end());
            
            vector<vector<int>> result;
            
            for (int i = 0; i < num.size(); i++) {
                
                vector<int> eachResult;
                int target = 0 - num[i];
                eachResult.push_back(num[i]);
                twoSum(num, i, target, eachResult, result);
                eachResult.pop_back();
                
                while (i + 1 < num.size() && num[i] == num[i + 1]) {
                    i++;
                }
            }
            
            return result;
        }
        
        
        void twoSum(vector<int> &num, int currentIndex, int target, vector<int> &eachResult, vector<vector<int>> &result) {
            int left = currentIndex + 1;
            int right = num.size() - 1;
            
            while (left < right) {
                
                int tmp = num[left] + num[right];
                if (tmp > target) {
                    right--;
                } else if (tmp < target) {
                    left++;
                } else {
                    eachResult.push_back(num[left]);
                    eachResult.push_back(num[right]);
                    result.push_back(eachResult);
                    eachResult.pop_back();
                    eachResult.pop_back();
                    
                    while (left + 1 < right && num[left] == num[left + 1]) {
                        left++;
                    }
                    
                    while (right - 1 > left && num[right] == num[right - 1]) {
                        right--;
                    }
                    left++;
                    right--;
                    
                } 
                
                
            }
            return;
            
        }
    
};


//-4 -1 -1 0 1 2



int main(int argc, const char * argv[])
{
    

    // insert code here...
    vector<int> num = {-1, 0, 1, 2, -1, -4};
    vector<int> temp;
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

