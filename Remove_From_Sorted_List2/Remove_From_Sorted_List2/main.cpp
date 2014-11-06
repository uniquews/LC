//
//  main.cpp
//  Remove_From_Sorted_List2
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//class Solution {
//public:
//    ListNode *deleteDuplicates(ListNode *head) {
//        if (head == nullptr || head->next == nullptr) {
//            return head;
//        }
//        
//        ListNode dummy(-1);
//        ListNode *tail = &dummy;
//        ListNode *cur = head;
//        bool isDup = false;
//        
//        while (cur != nullptr) {
//            while (cur->next != nullptr && cur->val == cur->next->val) {
//                isDup = true;
//                cur = cur->next;
//            }
//            
//            if (isDup == false) {
//                tail->next = cur;
//                cur = cur->next;
//                tail = tail->next;
//            } else {
//                cur = cur->next;
//                isDup = false;
//                tail->next = cur;
//            }
//        }
//        
//        return dummy.next;
//    }
//    
//};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        
        bool dup = false;
        ListNode dummy(-1);
        ListNode *prev = &dummy;
        ListNode *cur = head;
        
        while (cur != nullptr) {
            while (cur->next != nullptr && cur->val == cur->next->val) {
                cur = cur->next;
                dup = true;
            }
            
            if (dup) {
                dup = false;
            } else {
                prev->next = cur;
                prev = prev->next;
            }
            
            cur = cur->next;
        }
        return dummy.next;
    }
};
int main(int argc, const char * argv[])
{

    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
//    ListNode *c = new ListNode(1);
//    ListNode *d = new ListNode(1);
    ListNode *e = new ListNode(2);
    
    a->next = b;
    b -> next = e;
//    b->next = c;
//    c->next = d;
//    d->next = e;
    
    Solution su;
    su.deleteDuplicates(a);
    
    return 0;
}

