//
//  main.cpp
//  Single_Number2
//
//  Created by Shuai Wang on 7/3/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        unordered_map<int, int> tempMap;
        int result = 0;

        for(size_t i = 0; i<n; i++){
            unordered_map<int, int> ::iterator it = tempMap.find(A[i]);
            if(it!=tempMap.end()){
                it->second++;
            }else{
                tempMap[A[i]] = 1;
            }
        }
        
        
        unordered_map<int, int> :: iterator it2 = tempMap.begin();
        for(; it2!=tempMap.end(); it2++){
            if(it2->second == 1){
                result = it2->first;
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

