//
//  main.cpp
//  Copy_List_With_Random_Pointer
//
//  Created by Shuai Wang on 7/7/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode dummy(-1);
        dummy.next = head;
        if(head == nullptr) return nullptr;
        
        RandomListNode *cur = head;
        while(cur!=nullptr){
            RandomListNode *temp = new RandomListNode(cur->label);
            temp->next = cur->next;
            cur->next  = temp;
            cur = temp->next;
        }
        
        
        cur = head;
        while(cur != nullptr){
            RandomListNode *temp = cur->next;
            if(cur->random!=nullptr){
                temp->random = cur->random->next; //!!!!!
                
            }
            cur = temp->next;
        }
        
        cur = head;
        dummy.next = cur->next;
        while(cur!=nullptr){
            RandomListNode *temp = cur->next;
            cur->next = temp->next;//!!!!!
            if(temp->next!=nullptr){
                temp->next = temp->next->next;
            }
            cur = cur->next;
            
            
        }
        return dummy.next;
    }
    
};

int main(int argc, const char * argv[])
{
    RandomListNode *a = new RandomListNode(-1);
    a->next = nullptr;
    
    Solution s;
    s.copyRandomList(a);
    
    return 0;
}

