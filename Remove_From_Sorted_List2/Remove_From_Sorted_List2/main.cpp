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

//class Solution {
//public:
//    ListNode *deleteDuplicates(ListNode *head) {
//        if(head == nullptr) return nullptr;
//        ListNode dummy(-1);
//        dummy.next = head;
//        ListNode *prev = &dummy;
//        ListNode *cur = head;
//        while(cur){
//            bool duplicate = false;
//            while(cur->next!=nullptr && cur->next->val == cur->val){
//                ListNode *temp = cur;
//                cur = cur->next;
//                duplicate = true;
//                delete temp;
//            }
//            
//            if(duplicate){
//                ListNode *temp = cur;
//                cur = cur->next;
//                delete temp;
//                continue;
//            }
//            
//            prev->next = cur;
//            prev = cur;
//            cur = cur->next;
//        }
//        
//        prev->next = nullptr;
//        
//        return dummy.next;
//    }
//    
//};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode dummy(INT_MIN);
        ListNode *prev = &dummy;
        prev->next = head;
        
        ListNode *cur = head;
        
        while (cur != nullptr) {
            
            bool dup = false;
            while (cur->next !=nullptr && cur->val == cur->next->val) {
                cur = cur->next;
                dup = true;
            }
            
            if (dup == true) {
                cur = cur->next;
                continue;
            }
            
            prev->next = cur;
            prev = cur;
            cur = cur->next;
            
            
        }
        
        prev->next = nullptr; //{1，1，1，1}
        
        return dummy.next;
    }
};

int main(int argc, const char * argv[])
{

    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(1);
//    ListNode *c = new ListNode(1);
//    ListNode *d = new ListNode(1);
//    ListNode *e = new ListNode(2);
    
    a->next = b;
//    b->next = c;
//    c->next = d;
//    d->next = e;
    
    Solution su;
    su.deleteDuplicates(a);
    
    return 0;
}

