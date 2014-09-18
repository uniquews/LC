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
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        unordered_map<int, int> _map;
        for (int i = 0; i < numbers.size(); i++) {
            _map[numbers[i]] = i;
        }
        
        for (int i = 0; i < numbers.size(); i++) {
            int gap = target - numbers[i];
            if (_map.find(gap) != _map.end() && _map[gap] != i) {
                result.push_back(i + 1);
                result.push_back(_map[gap] + 1);
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

