//
//  main.cpp
//  Clone_Graph
//
//  Created by Shuai Wang on 8/23/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr) {
            return nullptr;
        }
        
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> hashMap;
        vector<UndirectedGraphNode *> nodeList;
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        hashMap[node] = newNode;
        nodeList.push_back(node);
        
        int start = 0;
        while (start < nodeList.size()) {
            UndirectedGraphNode *cur = nodeList[start];
            for (UndirectedGraphNode* n : cur->neighbors) {
                if (find(nodeList.begin(), nodeList.end(), n)  == nodeList.end()) {
                    UndirectedGraphNode *newNeigh = new UndirectedGraphNode(n->label);
                    hashMap[n] = newNeigh;
                    nodeList.push_back(n);
                }
            }
            
            start++;
        }
        
        
        for (int i = 0; i < nodeList.size(); i++) {
            UndirectedGraphNode *cur = nodeList[i];
            for (int j = 0; j < cur->neighbors.size(); j++) {
                UndirectedGraphNode *newCur = hashMap[cur];
                newCur->neighbors.push_back(hashMap[cur->neighbors[j]]);
            }
            
        }
        return hashMap[node];
        
    }
};


int main(int argc, const char * argv[])
{

    UndirectedGraphNode *a = new UndirectedGraphNode(0);
    UndirectedGraphNode *b = new UndirectedGraphNode(1);
    UndirectedGraphNode *c = new UndirectedGraphNode(1);
    
    a->neighbors.push_back(b);
    b->neighbors.push_back(c);
    c->neighbors.push_back(c);
    
    Solution su;
    cout << su.cloneGraph(a) -> label << endl;
    
    return 0;
}

