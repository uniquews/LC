//
//  main.cpp
//  MergeTwoSortedLinkedList
//
//  Created by Shuai Wang on 3/27/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;

class LinkList{
public:
    int val;
    LinkList *next;
    LinkList(int x):val(x), next(NULL){};
};



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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        ListNode *tail = &dummy;
        
        while (l1 != nullptr || l2 != nullptr) {
            int val1 = l1 == nullptr ? INT_MAX : l1->val;
            int val2 = l2 == nullptr ? INT_MAX : l2->val;
            
            if (val1 >= val2) {
                tail->next = l2;
                l2 = l2->next;
            } else {
                tail-> next = l1;
                l1 = l1->next;
            }
            
            tail = tail->next;
        }
        
        return dummy.next;
    }
    
};


int main(int argc, const char * argv[])
{

    // insert code here...
    
    LinkList *a1 = new LinkList(1);
    LinkList *a2 = new LinkList(2);
    LinkList *a3 = new LinkList(3);
    LinkList *b1 = new LinkList(31);
    LinkList *b2 = new LinkList(32);
    LinkList *b3 = new LinkList(33);
    
    a1->next=a2;
    a2->next=a3;
    b1->next=b2;
    b2->next=b3;
    
    
   LinkList *p = Solution::merge(a1, b1);
    
    for(;p!=nullptr;p=p->next)
        cout<<p->val<<endl;
    //cout<<"okjjjjj"<<endl;
    
    return 0;
}

