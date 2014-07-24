//
//  main.cpp
//  Linked_List_Cycle2
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

/*
 
 http://fisherlei.blogspot.com/2013/11/leetcode-linked-list-cycle-ii-solution.html
 
 After my modification:
 
 L(first) means from the beginning of the while loop, the total distance of first pointer
 L(second) means from the beginning of the while loop. the total distance of second pointer
 
 L(first) = X+nY+K;
 L(second) = X-1+mY+K;(because second pointer start at head->next, so it goes 1 fewer than frist pointer in X part)
 
 if L(first) = t
 then L(second) = 2t
 
 X+1+K = (m-2n)Y
 
 because !!!!!X cannot add 1, we cannot make X back to the previous of head, so just let K+1, second = second->next
 
 
 OR
 
 
 we can initilize a dummy
 
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        if(head == nullptr) return nullptr;
        ListNode *first = head;
        ListNode *second = head->next;
        
        while(first !=nullptr && second !=nullptr){
            if(first  == second) break;
            first = first->next;
            second = second->next;
            if(second == nullptr) break;  // do not return here
            second = second->next;
        }
        
        if(second == nullptr) return nullptr; // return here for:{1}, no cycle
        
        first = dummy;
        // second = second->next; // because X cannot add 1
        while(first!=second){
            first = first->next;
            second = second->next;
        }
        
        return first;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

