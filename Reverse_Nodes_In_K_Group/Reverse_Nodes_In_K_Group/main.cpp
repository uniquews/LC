//
//  main.cpp
//  Reverse_Nodes_In_K_Group
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
//    ListNode *reverseKGroup(ListNode *head, int k) {
//        if (head == nullptr || head -> next == nullptr ||k < 2) {
//            return head;
//        }
//        
//        ListNode dummy(-1);
//        ListNode *prev = &dummy;
//        dummy.next = head;
//        ListNode *cur = head;
//        
//        while (cur != nullptr) {
//            for (int i = 1; i < k && cur != nullptr; i++) {
//                cur = cur -> next;
//            }
//            
//            if (cur == nullptr) {
//                return dummy.next;
//            } else {
//                prev = reverseLinkedList(prev, prev -> next, 1, k);
//            }
//            
//            cur = prev -> next;
//            
//        }
//        
//        return dummy.next;
//        
//    }
//    
//    
//    ListNode *reverseLinkedList(ListNode *prev, ListNode *head, int start, int end) {
//        
//        ListNode *prepare = nullptr;
//        ListNode *cur = head;
//        
//        for (int i = start; i <= end; i++) {
//            if (i == 1) {
//                prepare = prev;
//            }
//            
//            if (i > start) {
//                prev -> next = cur -> next;
//                cur -> next = prepare -> next;
//                prepare -> next = cur;
//                cur = prev;
//            }
//            
//            prev = cur;
//            cur = cur -> next;
//            
//        }
//        
//        // move prepare to the last non nullptr
//        for (int i = 0; i < end - start + 1; i++) {
//            prepare = prepare -> next;
//        }
//        
//        return prepare;
//        
//    }
//    
//    
//    
//};

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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == nullptr || k <= 1) {
            return nullptr;
        }
        
        ListNode dummy(-1);
        ListNode *prev = &dummy;
        dummy.next = head;
        ListNode *cur = head;
        while (cur != nullptr) {
            
            for (int i = 1; i < k && cur != nullptr; i++) { //!!!!!!cur != nullptr
                cur = cur->next;
            }
            
            if (cur == nullptr) {
                return dummy.next;
            } else {
                prev = reverseNodes(prev, prev->next, 1, k);
            }
            
            cur = prev->next;
            
        }
        
        return dummy.next;
    }
    
    ListNode *reverseNodes(ListNode *prepare, ListNode *cur, int start, int end) {
        ListNode *prev = prepare;
        prev = cur;
        cur = cur->next;
        int k = end - start + 1;
        
        
        
        for (int i = start + 1; i <= end; i++) {
            prev->next = cur->next;
            cur->next = prepare->next;
            prepare->next = cur;
            cur = prev;
            
            prev = cur;
            cur = cur->next;
            
        }
        
        while (k > 0) {
            prepare = prepare->next;
            k--;
        }
        
        return prepare;
    }
    
    
};

int main(int argc, const char * argv[])
{

    ListNode * a = new ListNode(1);
    ListNode *b = new ListNode(2);
    a->next = b;
    Solution s;
    s.reverseKGroup(a, 2);
    
    return 0;
}

