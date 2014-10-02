//
//  main.cpp
//  Swap_Nodes_In_Pair
//
//  Created by Shuai Wang on 7/7/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//class Solution {
//public:
//    ListNode *swapPairs(ListNode *head) {
//        
//        if (head == nullptr || head -> next == nullptr) {
//            return head;
//        }
//        
//        ListNode dummy (-1);
//        ListNode *prev = &dummy;
//        
//        ListNode *p = prev;
//        ListNode *q = prev;
//        
//        while (prev -> next != nullptr && prev -> next -> next != nullptr) {
//            p = prev -> next;
//            q = prev -> next -> next;
//            
//            prev -> next = q;
//            p -> next = q -> next;
//            q -> next = p;
//            
//            prev = p;
//        }
//        
//        return dummy.next;
//    }
//};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        
        ListNode dummy(-1);
        ListNode *prepare = &dummy;
        dummy.next = head;
        
        int len = 0;
        ListNode *cur = head;
        while (cur != nullptr) {
            len++;
            cur = cur->next;
        }
        
        
        for (int i = 0; i < len; i = i + 2) {
            if (len - i < 2) {
                break;
            }
            
            prepare = reverselist(prepare);
        }
        
        return dummy.next;
    }
    
    
    ListNode *reverselist(ListNode *prepare) {
        ListNode *cur = prepare->next->next;
        ListNode *prev = prepare->next;
        
        prev->next = cur->next;
        cur->next = prepare->next;
        prepare->next = cur;
        prepare = prev;
        return prepare;
    }
};

int main(int argc, const char * argv[])
{

    ListNode *a = new ListNode (1);
    ListNode *b = new ListNode (2);
    ListNode *c = new ListNode (3);
    ListNode *d = new ListNode (4);
    ListNode *e = new ListNode (5);
    a -> next = b;
    b -> next = c;
    c->next = d;
    d->next = e;
    e->next = nullptr;
    Solution su;
    su.swapPairs(a);
    return 0;
}

