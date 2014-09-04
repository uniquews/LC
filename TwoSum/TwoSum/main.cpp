//
//  main.cpp
//  TwoSum
//
//  Created by Shuai Wang on 5/29/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;
//class Solution{
//public:
//    vector<int> twoSum(vector<int> &numbers, int target){
//        
//        vector<int> result;
//        unordered_map<int, int> mapping;
//        for(int i=0; i<numbers.size();i++){
//            mapping[numbers[i]]=i;
//        }
//        
//        for(int j=0; j<numbers.size(); j++){
//            const int temp= target-numbers[j];
//            if(mapping.find(temp)!=mapping.end()){
//                cout<<j<<endl;
//                if(j==mapping[temp])
//                    continue;
//                
//                result.push_back(j+1);
//                result.push_back(mapping[temp]+1);
//                break;
//            }
//        }
//        
//        
//        return result;
//    }
//};

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        
        vector<int> result;
        
        if (numbers.size() == 0) {
            return result;
        }
        
        int start = 0;
        int end = numbers.size() - 1;
        while (start < end) {
            if (numbers[start] + numbers[end] > target) {
                if (numbers[start] > numbers[end]) {
                    start++;
                } else {
                    end--;
                }
            } else if(numbers[start] + numbers[end] < target) {
                if (numbers[start] > numbers[end]) {
                    end--;
                } else {
                    start++;
                }
            } else {
                result.push_back(start);
                result.push_back(end);
            }
        }
        
        return result;
    }
};


int main(int argc, const char * argv[])
{

    // insert code here...

    Solution *s = new Solution();
    vector<int> num = {3,2,4};
    vector<int> &numbers = num;
    vector<int> result;
    result = s->twoSum(numbers, 6);
    
    
    vector<int>::iterator iter;
    for(iter = result.begin(); iter!=result.end();iter++){
        cout << *iter<<" ";
    }
    
    cout << endl;
    return 0;
}

