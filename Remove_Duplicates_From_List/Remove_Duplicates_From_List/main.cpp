//
//  main.cpp
//  Remove_Duplicates_From_List
//
//  Created by Shuai Wang on 7/6/14.
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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        
        ListNode *prev = head;
        ListNode *cur = head->next;
        
        while (cur != nullptr) {
            if (prev->val == cur->val) {
                prev->next = cur->next;
                cur = prev;
            }
            
            prev = cur;
            cur = cur->next;
        }
        return head;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

