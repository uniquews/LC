//
//  main.cpp
//  Swap_Nodes_In_Pair
//
//  Created by Shuai Wang on 7/7/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

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
    ListNode *swapPairs(ListNode *head) {
        ListNode dummy(-1);
        ListNode *prev = &dummy;
        dummy.next = head;
        
        while(head && head->next){
            ListNode *temp = head->next->next;
            prev->next = head->next;
            head->next->next = head;
            head->next = temp;
            prev = head;
            head = head->next;
        }
        
        
        return dummy.next;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

