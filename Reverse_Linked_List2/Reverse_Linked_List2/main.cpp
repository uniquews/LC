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
        dummy.next = head;
        
        ListNode *prepareToReverse;
        ListNode *prev = &dummy;
        
        for(int i=1; i<=n; i++){
            if(m == i){
                prepareToReverse = prev;
            }
            
            if(i >m){
                prev->next = head->next; //1
                head->next = prepareToReverse->next;//2
                prepareToReverse ->next = head;//2
                head = prev;//1
            }
            
            prev = head;
            head = head->next;
            
        }
        
        
        return dummy.next;
    }
};