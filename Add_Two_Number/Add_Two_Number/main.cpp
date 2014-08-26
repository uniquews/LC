//
//  main.cpp
//  Add_Two_Number
//
//  Created by Shuai Wang on 8/25/14.
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr && l2 == nullptr) {
            return nullptr;
        }
        
        ListNode dummy(-1);
        ListNode *prev = &dummy;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr) {
            int val1 = l1 == nullptr ? 0 : l1->val;
            int val2 = l2 == nullptr ? 0 : l2->val;
            int digit = val1 + val2 + carry;
            int result = digit % 10;
            carry = digit / 10;
            ListNode *newNode = new ListNode(result);
            prev -> next = newNode;
            prev = newNode;
            
            if (l1 != nullptr) {
                l1 = l1 -> next;
            }
            
            if (l2 != nullptr) {
                l2 = l2 ->next;
            }
            
        }
        
        if (carry > 0) {
            ListNode *newNode = new ListNode(carry);
            prev -> next = newNode;
        }
        
        return dummy.next;
    }
};

int main(int argc, const char * argv[])
{

    ListNode *l1 = new ListNode(5);
    ListNode *l2 = new ListNode (5);
    
    Solution su;
    ListNode *result = su.addTwoNumbers(l1, l2);
    ListNode *dis = result;
    
    while (dis != nullptr) {
        cout << dis->val << " ";
        dis = dis -> next;
    }
    
    cout << endl;
    return 0;
}

