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
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), parent(NULL),left(NULL), right(NULL){}
};


class Solution {
    
public:
    TreeNode* LCA (TreeNode *p, TreeNode *q) {
        vector<TreeNode *> first;
        vector<TreeNode *> second;
        
        TreeNode *tmp1 = p;
        while (tmp1->parent != nullptr) {
            first.push_back(tmp1);
            tmp1 = tmp1->parent;
        }
        
        TreeNode *tmp2 = q;
        while (tmp2->parent != nullptr) {
            second.push_back(tmp2);
            tmp2 = tmp2->parent;
        }
        
        
        int i = first.size() - 1;
        int j = second.size() - 1;
        
        while (i >= 0 && j >= 0) {
            if (first[i] != second[j]) {
                return first[i]->parent;
            }
            i--;
            j--;
            
        }
        
        if (i < 0) {
            return first[0];
        } else {
            return second[0];
        }
        
    }
    
};


//Divide and Conquer

//class Solution {
//
//public:
//
//    TreeNode* findLCA (TreeNode *root, TreeNode *p, TreeNode *q) {
//        if (root == nullptr || root == p || root == q) {
//            return root;
//        }
//
//        TreeNode *left = findLCA(root->left, p, q);
//        TreeNode *right = findLCA(root->right, p, q);
//
//        if (left != nullptr && right != nullptr) {
//            return root;
//        }
//
//        if (left != nullptr) {
//            return left;
//        }
//
//        if (right != nullptr) {
//            return right;
//        }
//
//        return nullptr; // in this sub-stree, no left and no right at all
//    }
//
//
//};

//class Solution {
//public:
//    TreeNode *LCA(TreeNode *p, TreeNode *q) {
//        if (p == nullptr || q == nullptr) {
//            return nullptr;
//        }
//        
//        TreeNode *root = p;
//        while (root->parent != nullptr) {
//            root = root->parent;
//        }
//        
//        TreeNode *lca = divide(root, p, q);
//        return lca;
//        
//    }
//    
//    TreeNode *divide(TreeNode *root, TreeNode *p, TreeNode *q) {
//        if (root == nullptr) {
//            return root;
//        }
//        
//        if (root == p || root == q) {
//            return root;
//        }
//        
//        TreeNode *leftResult = divide(root->left, p, q);
//        TreeNode *rightResult = divide(root->right, p, q);
//        
//        if (leftResult != nullptr && rightResult != nullptr) {
//            return root;
//        } else if (leftResult != nullptr) {
//            return leftResult;
//        } else if (rightResult != nullptr) {
//            return rightResult;
//        } else {
//            return nullptr;
//        }
//        
//        
//        
//    }
//    
//    
//    
//};

//class Solution {
//    
//public:
//    int LCA (TreeNode *p, TreeNode *q, TreeNode *root) {
//        if (p == nullptr || q == nullptr) {
//            return -1;
//        }
//        
//        if (p == root) {
//            return p->val;
//        }
//        
//        if(q == root) {
//            return q->val;
//        }
//        
//        int leftVal = LCA(p, q, root->left);
//        int rightVal = LCA(p, q, root->right);
//        
//        if (leftVal == -1 && rightVal == -1) {
//            return -1;
//        }
//        
//        if (leftVal != -1 && rightVal != -1) {
//            return root->val;
//        }
//        
//        if (leftVal != -1) {
//            return leftVal;
//        }
//        
//        if (rightVal != -1) {
//            return rightVal;
//        }
//        return -1;
//    }
//    
//};

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
    
    a->left = b;
    a->right = c;
    
    b->left = d;
    b->right = e;
    
    d->left = h;
    d->right = i;
    
    c->left = f;
    c->right = g;
    
    
    Solution su;
//    cout << su.findLCA(a, h, e) -> val << endl;
//    cout << su.LCA(e, nullptr)->val << endl;
    cout << su.LCA(i, c)->val << endl;
    
    
    return 0;
}

