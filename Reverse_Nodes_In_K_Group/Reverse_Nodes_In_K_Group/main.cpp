//
//  main.cpp
//  Reverse_Nodes_In_K_Group
//
//  Created by Shuai Wang on 7/7/14.
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == nullptr || k <= 1) {
            return head;
        }
        
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *prepare = &dummy;
        int len = 0;
        ListNode *cur = head;
        while (cur != nullptr) {
            len++;
            cur = cur->next;
        }
        
        
        if (len < k) {
            return head;
        }
        
        while (len >= k) {
            prepare = reverse(prepare, k);
            len = len - k;
        }
        return dummy.next;
    }
    
    
    ListNode *reverse(ListNode *prepare, int k) {
        ListNode *prev = prepare ->next;
        ListNode *cur = prepare->next->next;
        
        for (int i = 0; i < k - 1; i++) {
            prev->next = cur->next;
            cur->next = prepare->next;
            prepare->next = cur;
            cur = prev;
            prev = cur;
            cur = cur->next;
            
        }
        
        prepare = prev;
        
        return prepare;
    }
    
};
int main(int argc, const char * argv[])
{

    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    ListNode *d = new ListNode(4);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = nullptr;
    Solution s;
    ListNode *result = s.reverseKGroup(a, 2);
    
    while (result != nullptr) {
        cout << result->val << endl;
        result = result->next;
    }
     
    return 0;
}

