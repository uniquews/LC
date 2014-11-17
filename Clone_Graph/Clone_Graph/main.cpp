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
#include <queue>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

//class Solution {
//public:
//    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
//        if (node == nullptr) {
//            return nullptr;
//        }
//        
//        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> hashMap;
//        vector<UndirectedGraphNode *> nodeList;
//        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
//        hashMap[node] = newNode;
//        nodeList.push_back(node);
//        
//        int start = 0;
//        while (start < nodeList.size()) {
//            UndirectedGraphNode *cur = nodeList[start];
//            for (UndirectedGraphNode* n : cur->neighbors) {
//                if (find(nodeList.begin(), nodeList.end(), n)  == nodeList.end()) {
//                    UndirectedGraphNode *newNeigh = new UndirectedGraphNode(n->label);
//                    hashMap[n] = newNeigh;
//                    nodeList.push_back(n);
//                }
//            }
//            
//            start++;
//        }
//        
//        
//        for (int i = 0; i < nodeList.size(); i++) {
//            UndirectedGraphNode *cur = nodeList[i];
//            for (int j = 0; j < cur->neighbors.size(); j++) {
//                UndirectedGraphNode *newCur = hashMap[cur];
//                newCur->neighbors.push_back(hashMap[cur->neighbors[j]]);
//            }
//            
//        }
//        return hashMap[node];
//        
//    }
//};

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr) {
            return node;
        }
        
        vector<UndirectedGraphNode *> nodeList;
        queue<UndirectedGraphNode *> q;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode *> hashMap;
        nodeList.push_back(node);
        UndirectedGraphNode *newStart = new UndirectedGraphNode(node->label);
        hashMap[node] = newStart;
        q.push(node);
        int curLevel = (int)q.size();
        int nextLevel = 0;
        
        while (curLevel != 0) {
            UndirectedGraphNode *cur = q.front();
            q.pop();
            curLevel--;
            for (int i = 0; i < cur->neighbors.size(); i++) {
                if (hashMap.find(cur->neighbors[i]) == hashMap.end()) {
                    UndirectedGraphNode *newCurNeighbor = new UndirectedGraphNode(cur->neighbors[i]->label);
                    q.push(cur->neighbors[i]);
                    hashMap[cur->neighbors[i]] = newCurNeighbor;
                    nodeList.push_back(cur->neighbors[i]);
                    nextLevel++;
                    
                }
            }
            
            if (curLevel == 0) {
                curLevel = nextLevel;
                nextLevel = 0;
            }
        }
        
        for (int i = 0; i < nodeList.size(); i++) {
            UndirectedGraphNode *cur = nodeList[i];
            for (int j = 0; j < cur->neighbors.size(); j++) {
                hashMap[cur]->neighbors.push_back(hashMap[cur->neighbors[j]]);
            }
        }
        
        return newStart;
    }
};


int main(int argc, const char * argv[])
{

    UndirectedGraphNode *a = new UndirectedGraphNode(0);
    UndirectedGraphNode *b = new UndirectedGraphNode(1);
    UndirectedGraphNode *c = new UndirectedGraphNode(2);
    
    a->neighbors.push_back(b);
    b->neighbors.push_back(c);
    c->neighbors.push_back(c);
    
    Solution su;
    UndirectedGraphNode *result = su.cloneGraph(a);
    cout << result -> label << endl;
    
    return 0;
}

