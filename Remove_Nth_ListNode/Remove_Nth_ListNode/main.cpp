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
        
        ListNode dummy(0);
        dummy.next=head;
        ListNode *q= &dummy;
        ListNode *p = &dummy;
        while(n>0){
            q = q->next;
            n--;
        }
        while(q->next){
            p=p->next;
            q=q->next;
        }
        
        ListNode *temp = p->next;
        p->next = p->next->next;
        delete temp;
        return dummy.next; //cannot return head. head may be delelted. example:{1}, 1
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

