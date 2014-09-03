//
//  main.cpp
//  Smallest_Range_K_List
//
//  Created by Shuai Wang on 9/1/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater

using namespace std;

class Solution {
    

public:
    
    vector<int> findSmallestRange(vector<vector<int>> lists) {
        
        priority_queue<int, vector<int>, greater<int>> q;
        
        unordered_map <int, int> _mapIndex;
        for (int i = 0; i < lists.size(); i++) {
            _mapIndex[i] = 0;
            q.push(lists[i][0]);
            
        }
        
        while (1) {
            int smallest = q.top();
            
        }
        
    
    }

};

int main(int argc, const char * argv[])
{

//    priority_queue<int, vector<int>, greater<int>> queue;
//    queue.push(10);
//    queue.push(1);
//    queue.push(5);
//    queue.push(8);
//    queue.push(3);
    
//    while (queue.size() != 0) {
//        cout << queue.top() << " ";
//        queue.pop();
//    }
    
//    unordered_map<int, int> _map;
//    _map[1] = 2;
//    _map[1] = 4;
//    
//    cout << _map[1] << endl;
    return 0;
}

