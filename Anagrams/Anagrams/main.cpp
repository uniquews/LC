//
//  main.cpp
//  Anagrams
//
//  Created by Shuai Wang on 7/9/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> group;
        for(auto s: strs){
            string key = s;
            sort(key.begin(), key.end());
            group[key].push_back(s);
        }
        
        vector<string> result;
        for(auto it = group.begin(); it !=group.end(); it++){
            if(it->second.size() >1){
                result.insert(result.end(), it->second.begin(), it->second.end());
            }
        }
        
        return result;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

