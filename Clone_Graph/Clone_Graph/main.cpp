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
            return nullptr;
        }
        
        vector<UndirectedGraphNode *> nodeList;
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> nodeMap;
        
        nodeList.push_back(node);
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        nodeMap[node] = newNode;
        
        int index = 0;
        while (index < nodeList.size()) {
            UndirectedGraphNode *tmp = nodeList[index];
            index++;
            for (int i = 0; i < tmp->neighbors.size(); i++) {
                if (find(nodeList.begin(), nodeList.end(), tmp->neighbors[i]) != nodeList.end()) {
                    nodeList.push_back(tmp->neighbors[i]);
                    UndirectedGraphNode *newNeigh = new UndirectedGraphNode(tmp->neighbors[i]->label);
                    nodeMap[tmp->neighbors[i]] = newNeigh;
                }
                
            }
        }
        
        
        for (int i = 0; i < nodeList.size(); i++) {
            vector<UndirectedGraphNode *> thisNeigh = nodeList[i]->neighbors;
            for (int j = 0; j < thisNeigh.size(); j++) {
                nodeMap[nodeList[i]]->neighbors.push_back(nodeMap[thisNeigh[j]]);
            }
        }
        
        return nodeMap[node];
    }
};

//class Solution {
//public:
//    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
//        vector<UndirectedGraphNode *> nodes;
//        unordered_map <UndirectedGraphNode *, UndirectedGraphNode *> nodeMap;
//        int start = 0;
//        if (node == nullptr) {
//            return nullptr;
//        }
//        
//        nodes.push_back(node);
//        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
//        nodeMap[node] = newNode;
//        
//        //clone node
//        while (start < nodes.size()) {
//            UndirectedGraphNode *head = nodes[start++];
//            for (int i = 0; i < head->neighbors.size(); i++) {
//                UndirectedGraphNode *neigh = head->neighbors[i];
//                if (nodeMap.find(neigh) == nodeMap.end()) {
//                    nodes.push_back(neigh);
//                    UndirectedGraphNode *newNeigh = new UndirectedGraphNode(neigh->label);
//                    nodeMap[neigh] = newNeigh;
//                }
//            }
//        }
//        
//        //clone connection
//        for (int i = 0; i < nodes.size(); i++) {
//            UndirectedGraphNode *newNode = nodeMap[nodes[i]];
//            for (int j = 0; j < nodes[i]->neighbors.size(); j++) {
//                newNode->neighbors.push_back(nodeMap[nodes[i]->neighbors[i]]);
//            }
//        }
//        
//        
//        // delete newNode;
//        return nodeMap[node];
//        
//    }
//};

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

