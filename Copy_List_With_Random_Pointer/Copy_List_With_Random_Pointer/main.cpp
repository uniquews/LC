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



//class Solution {
//public:
//    RandomListNode *copyRandomList(RandomListNode *head) {
//        RandomListNode *cur = head;
//        if (head == nullptr) {
//            return nullptr;
//        }
//        
//        while (cur != nullptr) {
//            RandomListNode *tmp = new RandomListNode (cur -> label);
//            RandomListNode *nextNode = cur -> next;
//            tmp -> next = cur -> next;
//            cur -> next = tmp;
//            cur = nextNode;
//        }
//        
//        cur = head;
//        while (cur != nullptr) {
//            if (cur -> random != nullptr) {
//                cur -> next -> random = cur -> random -> next;
//            }
//            
//            cur = cur -> next -> next;
//        }
//        
//        cur = head;
//        RandomListNode *resultHead = head -> next;
//        while (cur != nullptr) {
//            RandomListNode *nextNode = cur -> next -> next;
//            if (nextNode != nullptr) {
//                cur -> next -> next = nextNode -> next;
//                cur -> next = nextNode;
//            } else {
//                cur -> next ->next = nullptr;
//                cur -> next = nullptr;
//            }
//            
//            cur = nextNode;
//        }
//        
//        return resultHead;
//        
//    }
//};

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == nullptr) {
            return nullptr;
        }
        
        RandomListNode *cur = head;
        while (cur != nullptr) {
            RandomListNode *newNode = new RandomListNode(cur->label);
            RandomListNode *oldNext = cur->next;
            cur->next = newNode;
            newNode->next = oldNext;
            cur = oldNext;
        }
        
        cur = head;
        while (cur != nullptr) {
            if (cur->random != nullptr) {
                RandomListNode *oldRandom = cur->random;
                RandomListNode *newNode = cur->next;
                newNode->random = oldRandom->next;
            }
            cur = cur->next->next;
        }
        
        cur = head;
        RandomListNode *newHead = head->next;
        while (cur != nullptr) {
            RandomListNode *oldNext = cur->next->next;
            RandomListNode *newNode = cur->next;
            if (oldNext != nullptr) {
                RandomListNode *newNext = oldNext->next;
                cur->next = oldNext;
                newNode->next = newNext;
                cur = oldNext;
            } else {
                cur->next = nullptr;
                newNode->next = nullptr;
                cur = oldNext;
                
            }
            
            
        }
        
        return newHead;
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

