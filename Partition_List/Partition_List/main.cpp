//
//  main.cpp
//  Partition_List
//
//  Created by Shuai Wang on 7/6/14.
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
    ListNode *partition(ListNode *head, int x) {
        if (head == nullptr) {
            return nullptr;
        }
        
        ListNode leftDummy(-1);
        ListNode rightDummy(-1);
        ListNode *leftTail = &leftDummy;
        ListNode *rightTail = &rightDummy;
        while (head != nullptr) {
            if (head->val < x) {
                leftTail->next = head;
                leftTail = leftTail->next;
            } else {
                rightTail->next = head;
                rightTail = rightTail->next;
            }
            head = head->next;
        }
        
        rightTail->next = nullptr;
        leftTail->next = rightDummy.next;
        return leftDummy.next;
    }
};

int main(int argc, const char * argv[])
{
    ListNode *a = new ListNode(1);
//    ListNode *b = new ListNode(4);
//    ListNode *c = new ListNode(3);
//    ListNode *d = new ListNode(2);
//    ListNode *e = new ListNode(5);
//    ListNode *f = new ListNode(2);
    a->next = nullptr;
//    a->next = b;
//    b->next = c;
//    c->next = d;
//    d->next = e;
//    e->next = f;
    
    Solution s;
    ListNode *result = s.partition(a, 0);
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    
    return 0;
}

