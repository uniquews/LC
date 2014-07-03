//
//  main.cpp
//  Gas_Station
//
//  Created by Shuai Wang on 7/2/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int sum = 0;
        // firstly, we decide if there is a solution
        for(int i=0; i < gas.size(); i++){
            sum += gas[i] - cost[i];
        }
        
        if(sum >=0){
            int startNode = 0; // Attention! don't use -1, because maybe the first node is valid, then 0 doesn't need to be changed.
            int leftGas = 0;
            for(int i=0; i< gas.size(); i++){
                leftGas += gas[i] - cost[i];
                if(leftGas < 0){
                    startNode = i+1;
                    leftGas = 0;
                }
            }
            
            return startNode;
        }else{
            return -1;
        }
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

