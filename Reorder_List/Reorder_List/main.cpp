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

//class Solution {
//public:
//    void reorderList(ListNode *head) {
//        if(head == nullptr) return;
//
//        ListNode *fast = head;
//        ListNode *slow = head;
//        
//        // find the median node
//        while(true){
//            fast = fast->next;
//            if(fast == nullptr)
//                break;
//            fast = fast ->next;
//            if(fast == nullptr)
//                break;
//            slow = slow->next;
//        }
//        
//        // reverse second half of link list
//        ListNode *cur = slow;
//        ListNode *prev = slow->next;
//        
//        cur->next = nullptr;
//        while(prev != nullptr){
//            ListNode *temp = prev->next;
//            prev->next = cur;
//            cur = prev;
//            prev = temp;
//            
//        }
//        
//        // merge two lists
//        ListNode *first = head;
//        ListNode *second = cur;
//        
//        while(first != nullptr && second != nullptr && first != second){
//            ListNode *nextFirst = first->next;
//            ListNode *nextSecond = second->next;
//            second->next = first->next;
//            first->next = second;
//            first = nextFirst;
//            second = nextSecond;
//        }
//        
//        return;
//    }
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
    void reorderList(ListNode *head) {
        if (head == nullptr) {
            return;
        }
        
        ListNode *mid = findMiddle(head);
        ListNode *tail = reverse(mid->next);
        mid->next = nullptr;
        merge(head, tail);
        return;
        
    }
    
    
    ListNode* findMiddle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head->next;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* reverse(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        
        ListNode dummy(-1);
        ListNode *prepare = &dummy;
        dummy.next = head;
        ListNode *prev = head;
        head = head->next;
        
        while (head != nullptr) {
            prev->next= head->next;
            head->next = prepare->next;
            prepare->next = head;
            head = prev;
            prev = head;
            head = head->next;
        }
        
        return dummy.next;
        
    }
    
    
    ListNode* merge (ListNode *head, ListNode *tail) {
        ListNode *result = head;
        if (head != nullptr) {
            result = head;
        } else {
            result = tail;
        }
        int flag = 1;
        while (head != nullptr && tail != nullptr) {
            if (flag % 2 != 0) {
                ListNode *tmp = head->next;
                head->next = tail;
                head = tmp;
                flag++;
            } else {
                ListNode *tmp = tail->next;
                tail->next = head;
                tail = tmp;
                flag++;
            }
        }
        
        return result;
    }
    
};

int main(int argc, const char * argv[])
{

    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);

    ListNode *c = new ListNode(3);
//    ListNode *d = new ListNode(4);
//    ListNode *e = new ListNode(5);
    
    a->next = b;
    b->next = c;
//    c->next = d;
//    d->next = e;
    
    Solution su;
    su.reorderList(a);
    
    

    return 0;
}

