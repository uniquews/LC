
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
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode dummy(-1);
        ListNode *prev = &dummy;
        dummy.next = head;
        ListNode *prepare = nullptr;
        
        for (int i = 1; i <= n; i++) {
            if (m == i) {
                prepare = prev;
            } else if (i > m) {
                prev->next = head->next;
                head->next = prepare->next;
                prepare->next = head;
                head = prev;
            }
            
            prev = head;
            head = head->next;
        }
        
        return dummy.next; // m=1时， prepare 指向dummy； m不等于1时，dummy.next本身也不会变
    }
    
};



int main() {

    ListNode * a = new ListNode(1);
    ListNode * b = new ListNode(2);
//    ListNode * c = new ListNode(3);
//    ListNode * d = new ListNode(4);
    
    a->next = b;
//    b->next = c;
//    c->next = d;
//    d->next = nullptr;
    
    Solution su;
    cout << su.reverseBetween(a, 2, 2)->val << endl;
    
    
    return 0;
}

