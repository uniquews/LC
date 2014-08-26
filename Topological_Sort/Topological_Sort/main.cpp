//
//  main.cpp
//  Topological_Sort
//
//  Created by Shuai Wang on 8/24/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> in;
    vector<UndirectedGraphNode *> out;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {

public:
    
    vector<UndirectedGraphNode *> topologicalSort (vector<UndirectedGraphNode *> nodeList) {
        
        // get in-degree
        for (auto node : nodeList) {
            
        }
    
    }


};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

