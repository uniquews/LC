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
        ListNode *cur = head;
        int length = 0;
        while(cur!=nullptr){
            cur = cur->next;
            length++;
        }
        
        ListNode *start = head;
        ListNode *nextStart = head->next;
        ListNode *last = head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = last;
        
        for(int i=0; i< length/2; i++){
            int lengthRemain = length-1-i;
            while(lengthRemain!=0){
                dummy = last;
                last = last->next;
                lengthRemain--;
            }
            
            if(start == last) break;
            
            dummy->next = last->next;
            last->next = start->next;
            start->next = last;
            start = nextStart;
            nextStart = nextStart->next;
            
            last = start;
        }
        return;
    }
};

int main(int argc, const char * argv[])
{

    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode ()
    return 0;
}

