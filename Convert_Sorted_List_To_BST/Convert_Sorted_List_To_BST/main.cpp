//
//  main.cpp
//  Convert_Sorted_List_To_BST
//
//  Created by Shuai Wang on 9/17/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int len = 0;
        ListNode *p = head;
        while (p) {
            len++;
            p = p->next;
        }
        
        return build(head, 0, len - 1);
    }
    
    TreeNode *build(ListNode *&head, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        
        int mid = start + (end - start) / 2;
        TreeNode *leftChild = build(head, start, mid - 1);
        TreeNode *parent = new TreeNode(head->val);
        parent->left = leftChild;
        head = head->next;

        
        parent->right = build(head, mid + 1, end);
        return parent;
    }
};

int main(int argc, const char * argv[])
{

    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    ListNode *d = new ListNode(4);
    ListNode *e = new ListNode(5);
    
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = nullptr;
    
    Solution su;
    su.sortedListToBST(a);
    return 0;
}

