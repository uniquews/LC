//
//  main.cpp
//  RecoverBST
//
//  Created by Shuai Wang on 6/9/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Tree{
public:
    TreeNode *root;
    Tree(TreeNode *t): root(t){};
    
};

//class Solution {
//public:
//    void recoverTree(TreeNode *root) {
//        if (root == nullptr) {
//            return;
//        }
//        
//        pair<TreeNode *, TreeNode*> broken;
//        TreeNode *cur = root;
//        TreeNode *prev = nullptr;
//        
//        while (cur != nullptr) {
//            if (cur->left == nullptr) {
//                detect(broken, prev, cur);
//                prev = cur;
//                cur = cur->right;
//            } else {
//                TreeNode *node = cur->left;
//                while (node->right != nullptr && node->right != cur) {
//                    node = node->right;
//                }
//                
//                if (node->right == nullptr) {
//                    node->right = cur;
//                    cur = cur->left;
//                } else {
//                    node->right = nullptr;
//                    detect(broken, prev, cur);
//                    prev = cur;
//                    cur = cur->right;
//                }
//            }
//        }
//        
//        swap(broken.first->val, broken.second->val);
//        return;
//        
//    }
//    
//    void detect(pair<TreeNode *, TreeNode *> &broken, TreeNode *prev, TreeNode *cur) {
//        if (prev != nullptr && prev->val > cur->val) {
//            broken.first = prev;
//        }
//        
//        broken.second = cur;
//        
//        return;
//    }
//    
//    
//};
class Solution {
    
private:
    TreeNode *firstElement = nullptr;
    TreeNode *secondElement = nullptr;
    TreeNode *lastElement = new TreeNode(INT_MIN);
    
public:
    void recoverTree(TreeNode *root) {
        traverse(root);
        // swap(firstElement->val, secondElement->val);
        int tmp = firstElement->val;
        firstElement->val = secondElement->val;
        secondElement->val = tmp;
        return;
        
    }
    
    void traverse(TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        
        traverse(node->left);
        if (firstElement == nullptr && node->val < lastElement->val) {
            firstElement = lastElement;
        }
        
        if (firstElement != nullptr && node->val < lastElement->val) {
            secondElement = node;
        }
        
        lastElement = node;
        traverse(node->right);
        return;
    }
};



int main(int argc, const char * argv[])
{

    // insert code here...
//    TreeNode *root = new TreeNode(10);
//    Tree t(root);
//    TreeNode *a = new TreeNode(7);
//    TreeNode *b = new TreeNode(3);
//    TreeNode *c = new TreeNode(8);
//    TreeNode *d = new TreeNode(13);
//    TreeNode *e = new TreeNode(5);
//    
//    TreeNode *root = new TreeNode(2);
//    Tree t(root);
//    TreeNode *a = new TreeNode(3);
//    TreeNode *b = new TreeNode(1);
//    
//    root->left = a;
//    root->right = d;
//    a->left = b;
//    a->right = c;
//    d->left = e;
    
    
//    TreeNode *a = new TreeNode (2);
//    TreeNode *b = new TreeNode (3);
//    TreeNode *c = new TreeNode (1);
//    
//    a->right = b;
//    b->left = c;
    
    TreeNode *a = new TreeNode (0);
    TreeNode *b = new TreeNode (1);
    a->left = b;
    Solution s;
    s.recoverTree(a);
    
//    vector<int> r = s.inorderTraversal(root);
//    
//    vector<int>::iterator it = r.begin();
//    for(; it!=r.end(); it++){
//        cout << *it<<"--";
//    }
//    cout << endl;
    
    

    return 0;
}

