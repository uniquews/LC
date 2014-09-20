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
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        
        if (head == nullptr || head -> next == nullptr) {
            return head;
        }
        
        ListNode dummy (-1);
        ListNode *prev = &dummy;
        
        ListNode *p = prev;
        ListNode *q = prev;
        
        while (prev -> next != nullptr && prev -> next -> next != nullptr) {
            p = prev -> next;
            q = prev -> next -> next;
            
            prev -> next = q;
            p -> next = q -> next;
            q -> next = p;
            
            prev = p;
        }
        
        return dummy.next;
    }
};

int main(int argc, const char * argv[])
{

    ListNode *a = new ListNode (1);
    ListNode *b = new ListNode (2);
    a -> next = b;
    b -> next = nullptr;
    Solution su;
    su.swapPairs(a);
    return 0;
}

