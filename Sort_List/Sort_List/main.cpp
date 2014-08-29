//
//  main.cpp
//  Sort_List
//
//  Created by Shuai Wang on 7/24/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};




class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head -> next == nullptr) {
            return head;
        }
        
        ListNode *mid = findMiddle(head);
        ListNode *right = sortList(mid -> next);
        mid -> next = nullptr;
        ListNode *left = sortList(head);
        
        return merge(left, right);
    }
    
    ListNode *findMiddle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head -> next;
        
        while (fast != nullptr && fast -> next != nullptr) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        
        return slow;
    
    }
    
    ListNode *merge(ListNode *head1, ListNode *head2) {
        ListNode dummy(-1);
        ListNode *prev = &dummy;
        
        while (head1 != nullptr || head2 != nullptr) {
            int val1 = head1 == nullptr ? INT_MAX : head1 -> val;
            int val2 = head2 == nullptr ? INT_MAX : head2 -> val;
            
            if (val1 <  val2) {
                prev -> next = head1;
                head1 = head1 -> next;
            } else {
                prev -> next = head2;
                head2 = head2 -> next;
            }
            
            prev = prev -> next;
        
        }
        
        return dummy.next;
    
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
    ListNode *g = new ListNode(6);
    ListNode *h = new ListNode(7);
    
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;
    g->next = h;
    
    ListNode *result = su.sortList(a);
    
    while (result != nullptr) {
        cout << result -> val << " ";
        result = result -> next;
    }
    
    cout << endl;
    
    return 0;
}

