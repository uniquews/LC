//
//  main.cpp
//  Reorder_List
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
    void reorderList(ListNode *head) {
        if(head == nullptr) return;
        ListNode *fast = head;
        ListNode *slow = head;
        
        // find the median node
        while(true){
            fast = fast->next;
            if(fast == nullptr)
                break;
            fast = fast ->next;
            if(fast == nullptr)
                break;
            slow = slow->next;
        }
        
        // reverse second half of link list
        ListNode *cur = slow;
        ListNode *prev = slow->next;
        
        cur->next = nullptr;
        while(prev != nullptr){
            ListNode *temp = prev->next;
            prev->next = cur;
            cur = prev;
            prev = temp;
            
        }
        
        // merge two lists
        ListNode *first = head;
        ListNode *second = cur;
        
        while(first != nullptr && second != nullptr && first != second){
            ListNode *nextFirst = first->next;
            ListNode *nextSecond = second->next;
            second->next = first->next;
            first->next = second;
            first = nextFirst;
            second = nextSecond;
        }
        
        return;
    }
    
};

int main(int argc, const char * argv[])
{

    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
//    ListNode *c = new ListNode(3);
//    ListNode *d = new ListNode(4);
//    ListNode *e = new ListNode(5);
    
    a->next = b;
//    b->next = c;
//    c->next = d;
//    d->next = e;
    
    Solution su;
    su.reorderList(a);
    
    
    return 0;
}

