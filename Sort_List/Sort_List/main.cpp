//
//  main.cpp
//  Sort_List
//
//  Created by Shuai Wang on 7/24/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//class Solution {
//public:
//    ListNode *sortList(ListNode *head) {
//        if (head == nullptr || head->next == nullptr) {
//            return nullptr;
//        }
//        
//        ListNode *mid = findMiddle(head);
//        ListNode *rightHalf = mid->next;
//        mid->next = nullptr;
//        ListNode *leftHalf = sortList(head);
//        rightHalf = sortList(rightHalf);
//        return merge(leftHalf, rightHalf);
//    }
//    
//    
//    ListNode *findMiddle(ListNode *head) {
//        if (head == nullptr) {
//            return nullptr;
//        }
//        
//        ListNode *slow = head;
//        ListNode *fast = head->next;
//        
//        while (fast != nullptr && fast->next != nullptr) {
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//        
//        return slow;
//    }
//    
//    
//    ListNode *merge(ListNode *leftHalf, ListNode *rightHalf) {
//        if (leftHalf == nullptr && rightHalf == nullptr) {
//            return nullptr;
//        }
//        
//        ListNode dummy(-1);
//        ListNode *prev = &dummy;
//        
//        while (leftHalf != nullptr || rightHalf != nullptr) {
//            int val1 = leftHalf == nullptr ? INT_MAX : leftHalf->val;
//            int val2 = rightHalf == nullptr ? INT_MAX : rightHalf->val;
//            
//            if (val1 < val2) {
//                prev->next = leftHalf;
//                leftHalf = leftHalf->next;
//            } else {
//                prev->next = rightHalf;
//                rightHalf = rightHalf->next;
//            }
//            
//            prev = prev->next;
//        }
//        
//        return dummy.next;
//    }
//};

//class Solution {
//public:
//    ListNode *sortList(ListNode *head) {
//        if (head == nullptr || head -> next == nullptr) {
//            return head;
//        }
//        
//        ListNode *mid = findMiddle(head);
//        mid -> next = nullptr;
//        ListNode *left = sortList(head);
//        
//        ListNode *tmp = mid -> next;
//        
//        ListNode *right = sortList(tmp);
//        
//        return merge(left, right);
//    }
//    
//    ListNode *findMiddle(ListNode *head) {
//        if (head == nullptr) {
//            return nullptr;
//        }
//        
//        ListNode *slow = head;
//        ListNode *fast = head -> next;
//        
//        while (fast != nullptr && fast -> next != nullptr) {
//            slow = slow -> next;
//            fast = fast -> next -> next;
//        }
//        return slow;
//    }
//    
//    
//    ListNode *merge(ListNode *left, ListNode *right) {
//        ListNode dummy(-1);
//        ListNode *prev = &dummy;
//        
//        while (left != nullptr || right != nullptr) {
//            int val1 = left == nullptr ? INT_MAX: left -> val;
//            int val2 = right == nullptr ? INT_MAX : right -> val;
//            
//            if (val1 > val2) {
//                prev -> next = right;
//                right = right -> next;
//                prev = prev -> next;
//            } else {
//                prev -> next = left;
//                left = left -> next;
//                prev = prev -> next;
//            }
//            
//        }
//        return dummy.next;
//        
//    }
//};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//class Solution {
//public:
//    ListNode *sortList(ListNode *head) {
//        if (head == nullptr || head->next == nullptr) {
//            return head;
//        }
//        
//        ListNode *middle = findMiddle(head);
//        ListNode *rightNode = middle->next;
//        middle->next = nullptr;
//        ListNode *leftNode = sortList(head);
//        rightNode = sortList(rightNode);
//        leftNode = merge(leftNode, rightNode);
//        return leftNode;
//    }
//    
//    ListNode *findMiddle(ListNode *head) {
//        if (head == nullptr || head->next == nullptr) {
//            return head;
//        }
//        ListNode *first = head;
//        ListNode *second = head->next;
//        
//        while (second != nullptr && second->next != nullptr) {
//            first = first->next;
//            second = second->next->next;
//        }
//        
//        return first;
//        
//    }
//    
//    ListNode *merge(ListNode *p, ListNode *q) {
//        ListNode dummy(-1);
//        ListNode *prev = &dummy;
//        while (p != nullptr || q != nullptr) {
//            int val1 = p == nullptr ? INT_MAX : p->val;
//            int val2 = q == nullptr ? INT_MAX : q->val;
//            if (val1 <= val2) {
//                prev->next = p;
//                p = p->next;
//            } else {
//                prev->next = q;
//                q = q->next;
//            }
//            prev = prev->next;
//            
//        }
//        
//        return dummy.next;
//    }
//    
//};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//class Solution {
//public:
//    ListNode *sortList(ListNode *head) {
//        if (head == nullptr || head->next == nullptr) {
//            return head;
//        }
//        
//        ListNode *middle = findMiddle(head);
//        ListNode *rightNode = middle->next;
//        middle->next = nullptr;
//        ListNode *leftNode = sortList(head);
//        rightNode = sortList(rightNode);
//        return merge(leftNode, rightNode);
//    }
//    
//    ListNode *findMiddle (ListNode *head) {
//        if (head == nullptr || head->next == nullptr) {
//            return head;
//        }
//        
//        ListNode *slow = head;
//        ListNode *fast = head->next;
//        while (fast != nullptr && fast->next != nullptr) {
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//        
//        return slow;
//    }
//    
//    ListNode *merge(ListNode *p, ListNode *q) {
//        if (p == nullptr && q == nullptr) {
//            return nullptr;
//        }
//        
//        ListNode dummy(-1);
//        ListNode *tail = &dummy;
//        
//        while (p != nullptr || q != nullptr) {
//            int val1 = p == nullptr ? INT_MAX : p->val;
//            int val2 = q == nullptr ? INT_MAX : q->val;
//            
//            if (val1 <= val2) {
//                tail->next = p;
//                p = p->next;
//            } else {
//                tail->next = q;
//                q = q->next;
//            }
//            
//            tail = tail->next;
//        }
//        
//        return dummy.next;
//    }
//};

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
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode *middle = findMiddle(head);
        ListNode *left = head;
        ListNode *right = middle->next;
        
        middle->next = nullptr;
        left = sortList(left);
        right = sortList(right);
        return merge(left, right);
    }
    
    ListNode *findMiddle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head->next;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode *merge(ListNode *left, ListNode *right) {
        ListNode dummy(-1);
        ListNode *tail = &dummy;
        
        while (left != nullptr || right != nullptr) {
            int val1 = left == nullptr ? INT_MAX : left->val;
            int val2 = right == nullptr ? INT_MAX : right->val;
            if (val1 < val2) {
                tail->next = left;
                left = left->next;
            } else {
                tail->next = right;
                right = right->next;
            }
            tail = tail->next;
            
        }
        
        return dummy.next;
    }
};
int main(int argc, const char * argv[])
{

    Solution su;
    ListNode *a  = new ListNode(2);
    ListNode *b = new ListNode(1);
    ListNode *c = new ListNode (1);
    ListNode *d = new ListNode(2);
    ListNode *e = new ListNode(8);
    ListNode *f = new ListNode (9);
    ListNode *g = new ListNode(6);
    ListNode *h = new ListNode(7);
    
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;
    g->next = h;
    
    ListNode *result = su.sortList(a);
    
    while (result != nullptr) {
        cout << result -> val << " ";
        result = result -> next;
    }
    
    cout << endl;
    
    return 0;
}

