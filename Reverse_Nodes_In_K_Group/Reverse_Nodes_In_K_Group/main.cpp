//
//  main.cpp
//  Reverse_Nodes_In_K_Group
//
//  Created by Shuai Wang on 7/7/14.
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == nullptr || head->next == nullptr || k < 2) return head;
        ListNode dummy(-1);
        dummy.next = head;
        for(ListNode *prev = &dummy, *end = head; end; end = prev->next) {
            for (int i = 1; i < k && end; i++)
                end = end->next;
            if (end == nullptr) break; // 不足 k 个
            prev = reverse(prev, prev->next, 1, k);

        }
        return dummy.next;
    }
    
    
    
    ListNode* reverse(ListNode *dummy, ListNode * head, int m, int n){
        
        
        ListNode *prepareToReverse = nullptr;
        ListNode *prev = dummy;
        
        for(int i=1; i<=n; i++){
            if(m == i){
                prepareToReverse = prev;
            }
            
            if(i >m){
                prev->next = head->next;
                head->next = prepareToReverse->next;
                prepareToReverse ->next = head;
                head = prev;
            }
            
            prev = head;
            head = head->next;
            
        }
        
        for(int i=0; i<n;i++){
            dummy = dummy->next;
        }
        
        return dummy;
    }
};

int main(int argc, const char * argv[])
{

    ListNode * a = new ListNode(1);
    ListNode *b = new ListNode(2);
    a->next = b;
    Solution s;
    s.reverseKGroup(a, 2);
    
    return 0;
}
