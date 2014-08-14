//
//  main.cpp
//  Lower_Common_Ancestor
//
//  Created by Shuai Wang on 8/13/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *parent;
    TreeNode(int x) : val(x), parent(NULL) {}
};

class Solution {

public:
    
    vector<TreeNode *>findRoot (TreeNode *node) {
        
        if (node->parent == nullptr) {
            return vector<TreeNode *> {};
        }
        
        vector<TreeNode *> nodeList;
        
        while (node != nullptr) {
            nodeList.push_back(node);
            node = node->parent;
        }

        
        return nodeList; // root;
    }
    
    TreeNode *findAncestor (TreeNode *node1, TreeNode *node2) {
        if (node1 == nullptr || node2 == nullptr) {
            return nullptr;
        }
        
        vector<TreeNode *> nodeList1 = findRoot(node1);
        vector<TreeNode *> nodeList2 = findRoot(node2);
        
        int i = (int)nodeList1.size() - 1;
        int j = (int)nodeList2.size() - 1;
        
        for (; i >= 0, j >= 0; i--, j--) {
            if (nodeList1[i] != nodeList2[j]) {
                return nodeList1[i]->parent;
            }
            
        }
        
        
        return nullptr;
    }
    
};

int main(int argc, const char * argv[])
{

    TreeNode *a = new TreeNode (1);
    TreeNode *b = new TreeNode (2);
    TreeNode *c = new TreeNode (3);
    TreeNode *d = new TreeNode (4);
    TreeNode *e = new TreeNode (5);
    TreeNode *f = new TreeNode (6);
    TreeNode *g = new TreeNode (7);
    TreeNode *h = new TreeNode (8);
    TreeNode *i = new TreeNode (9);
    
    b->parent = a;
    c->parent = a;
    d->parent = b;
    e->parent = b;
    f->parent = c;
    g->parent = c;
    h->parent = d;
    i->parent = d;
    
    Solution su;
    cout << su.findAncestor(h, e) -> val << endl;
    
    
    return 0;
}

