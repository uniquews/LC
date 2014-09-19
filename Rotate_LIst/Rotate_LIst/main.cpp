//
//  main.cpp
//  Rotate_LIst
//
//  Created by Shuai Wang on 7/6/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        ListNode *cur = head;
        ListNode *tail = nullptr;
        
        if (head == nullptr || k == 0) {
            return head;
        }
        
        int length = 0;
        
        while (cur != nullptr) {
            if (cur -> next == nullptr) {
                tail = cur;
            }
            cur = cur->next;
            length++;
            
        }
        
        k = k % length;
        tail -> next = head;
        
        int step = length - k;
        cur = head;
        
        while (step > 1) {
            cur = cur -> next;
            step--;
        }
        
        ListNode *newHead = cur -> next;
        cur -> next = nullptr;
        
        return newHead;
        
        
    }
};
int main(int argc, const char * argv[])
{

    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    a->next = b;
    b->next = nullptr;
    Solution su;
    su.rotateRight(a, 1);
    return 0;
}

