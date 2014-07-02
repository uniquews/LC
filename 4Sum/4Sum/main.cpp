//
//  main.cpp
//  4Sum
//
//  Created by Shuai Wang on 7/2/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &num, int target) {
        
        if(num.size()<4) return vector<vector<int>> {};
        sort(num.begin(), num.end());
        
        map<int, vector<pair<int, int>>> cache; // store each two numbers sum as a pair
        for(size_t first =0; first< num.size()-1; first++){
            for(size_t second = first+1; second < num.size(); second++){
                int key = num[first] + num[second];
                cache[key].push_back(make_pair(first, second)); // store the index
            }
        }
        
        set<vector<int>> result;
        for(size_t third = 2; third < num.size()-1; third++){
            for(size_t fourth = third+1; fourth < num.size(); fourth++){
                int gap = target - num[third] - num[fourth];
                if(cache.find(gap)!=cache.end()){
                    for(size_t k =0; k< cache[gap].size(); k++){
                        if(third <= cache[gap][k].second)
                            continue;
                        result.insert(vector<int>{num[cache[gap][k].first], num[cache[gap][k].second], num[third], num[fourth]});
                    }
                }
            }
        }
        
        return vector<vector<int>> {result.begin(), result.end()};
        
    }
    
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

