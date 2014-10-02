//
//  main.cpp
//  Remove_Nth_ListNode
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

//class Solution {
//public:
//    ListNode *removeNthFromEnd(ListNode *head, int n) {
//        ListNode dummy(-1);
//        ListNode *prevDelete = &dummy;
//        prevDelete->next = head;
//        
//        for (int i = 0; i < n; i++) {
//            if (head == nullptr) {
//                return head;
//            }
//            head = head->next;
//        }
//        
//        while (head != nullptr) {
//            head = head->next;
//            prevDelete = prevDelete->next;
//        }
//        
//        prevDelete->next = prevDelete->next->next;
//        return dummy.next;
//        
//    }
//    
//};

//class Solution {
//public:
//    ListNode *removeNthFromEnd(ListNode *head, int n) {
//        if (head == nullptr) {
//            return head;
//        }
//        
//        ListNode dummy(-1);
//        ListNode *prev = &dummy;
//        ListNode *cur = &dummy;
//        dummy.next = head;
//        
//        while (n > 0) {
//            cur = cur->next;
//            n--;
//        }
//        
//        while (cur->next != nullptr) {
//            cur = cur->next;
//            prev = prev->next;
//        }
//        
//        prev->next = prev->next->next;
//        return dummy.next;
//    }
//};
//
//int main(int argc, const char * argv[])
//{
//
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}

#include <stdio.h>
int main(void)
{
    int arr[] = {10, 20};
    int *p = arr;
    *++p;
    printf("arr[0] = %d, arr[1] = %d, *p = %d", arr[0], arr[1], *p);
    return 0;
}


