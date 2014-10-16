
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 

//class Solution {
//public:
//    ListNode *reverseBetween(ListNode *head, int m, int n) {
//        if (head == nullptr) {
//            return nullptr;
//        }
//        
//        int len = 0;
//        ListNode *tmp = head;
//        while (tmp != nullptr) {
//            len++;
//            tmp = tmp->next;
//        }
//        
//        ListNode *cur = head;
//        ListNode dummy(-1);
//        ListNode *prev = &dummy;
//        dummy.next = head;
//        ListNode *prepare = nullptr;
//        
//        for (int i = 1; i <= len; i++) {
//            if (i == m) {
//                prepare = prev;
//            } else if (i > m && i <= n) {
//                prev->next = cur->next;
//                cur->next = prepare->next;
//                prepare->next = cur;
//                cur = prev;
//            }
//            
//            prev = cur;
//            cur = cur->next;
//        }
//        
//        return dummy.next;
//        
//    }
//};


//普通reverse whole linkedlist
class Solution {
    
public:
    ListNode *reverseLinkedlist(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode dummy(-1);
        dummy.next = head;
        
        ListNode *prev = head;
        ListNode *prepare = &dummy;
        
        ListNode *cur = head->next;
        
        while (cur != nullptr) {
            prev->next = cur->next;
            cur->next = prepare->next;
            prepare->next = cur;
            cur = prev;
            cur = cur->next;
            
        }
        
        return dummy.next;
        
    }
    
    
};

int main() {

    ListNode * a = new ListNode(1);
    ListNode * b = new ListNode(2);
    ListNode * c = new ListNode(3);
    ListNode * d = new ListNode(4);
    
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = nullptr;
    
    Solution su;
//    cout << su.reverseBetween(a, 1, 2)->val << endl;
    ListNode *result = su.reverseLinkedlist(a);
    while (result != nullptr) {
        cout << result->val << endl;
        result = result->next;
    }
//    cout << su.reverseLinkedlist(a)->val << endl;
    
    return 0;
}

