//
//  main.cpp
//  Sort_List
//
//  Created by Shuai Wang on 7/24/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *sortList(ListNode *head) {
        
        if(head == nullptr) return nullptr;
        
        // calculate length
        ListNode *it = head;
        int length = 0;
        while(it!=nullptr){
            length++;
            it = it->next;
        }
        
        ListNode *newHead = mergeSort(&head, length);
        return newHead;
    }
    
    
    
    ListNode* mergeSort(ListNode **head, int length){
        if(length == 1){
            ListNode *temp = *head;
            *head = (*head)->next;
            temp->next=nullptr;
            return temp;
        }
        
        ListNode *leftHead = mergeSort(head, length/2);
        ListNode *rightHead = mergeSort(head, length-length/2);
        ListNode *newHead = merge(leftHead, rightHead);
        return newHead;
    }
    
    ListNode* merge(ListNode *leftHead, ListNode *rightHead){
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while(leftHead !=nullptr || rightHead !=nullptr){
            int lVal = leftHead==nullptr?INT_MAX:leftHead->val;
            int rVal = rightHead==nullptr?INT_MAX:rightHead->val;
            
            if(lVal <= rVal){
                cur->next = leftHead;
                cur= cur->next;
                leftHead = leftHead->next;
            }else{
                cur->next = rightHead;
                cur = cur->next;
                rightHead = rightHead->next;
            }
        }
        cur = dummy->next;
        delete dummy;
        return cur;
    }
    
};



int main(int argc, const char * argv[])
{

    Solution su;
    ListNode *a  = new ListNode(5);
    ListNode *b = new ListNode(4);
    ListNode *c = new ListNode (1);
    ListNode *d = new ListNode(2);
    ListNode *e = new ListNode(8);
    ListNode *f = new ListNode (9);
    ListNode *g = new ListNode(7);
    ListNode *h = new ListNode(6);
    
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;
    g->next = h;
    
    su.sortList(a);
    return 0;
}

