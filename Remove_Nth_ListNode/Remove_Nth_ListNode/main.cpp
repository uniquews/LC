//
//  main.cpp
//  Remove_Nth_ListNode
//
//  Created by Shuai Wang on 7/6/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy(-1);
        ListNode *prevDelete = &dummy;
        prevDelete->next = head;
        
        for (int i = 0; i < n; i++) {
            if (head == nullptr) {
                return head;
            }
            head = head->next;
        }
        
        while (head != nullptr) {
            head = head->next;
            prevDelete = prevDelete->next;
        }
        
        prevDelete->next = prevDelete->next->next;
        return dummy.next;
        
    }
    
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

