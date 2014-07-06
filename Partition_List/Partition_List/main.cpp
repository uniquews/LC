//
//  main.cpp
//  Partition_List
//
//  Created by Shuai Wang on 7/6/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>


struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if(head==nullptr) return nullptr;
        ListNode *leftDummy = new ListNode(-1);
        ListNode *right_dummy = new ListNode(-1);
        ListNode* leftStart = leftDummy;
        ListNode * rightStart  = right_dummy;
        
        for(; head!=nullptr; head = head->next){
            if(head->val >= x){
                right_dummy->next = head;
                right_dummy = right_dummy->next;
            }else{
                leftDummy->next  = head;
                leftDummy = leftDummy->next;
            }
        }
        
        leftDummy->next = rightStart->next;
        right_dummy->next = nullptr;
        return leftStart->next;
        
    }
};

int main(int argc, const char * argv[])
{
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    b->next = a;
    Solution s;
    s.partition(b, 1);
    
    return 0;
}

