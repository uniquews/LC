class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *link1 = l1;
        ListNode *link2 = l2;
        ListNode *prev = l1;
        int carry = 0;
        while(link1!=nullptr|| link2!=nullptr){
            if(link1!=nullptr && link2!=nullptr){
                int temp = link1->val + link2->val + carry;
                link1->val = temp %10;
                carry = temp/10;
                prev = link1;
                link1 = link1->next;
                link2 = link2->next;
            }else if(link1!= nullptr && link2 == nullptr){
                int temp = link1->val +carry;
                link1->val = temp%10;
                carry = temp/10;
                prev = link1;
                link1= link1->next;
            }else if(link1 == nullptr && link2 != nullptr){
                ListNode * nextLinkNode = link2;
                prev->next = nextLinkNode;
                int temp = link2->val + carry;
                nextLinkNode->val = temp %10;
                carry  = temp/10;
                link2 = link2->next;
                prev = nextLinkNode;
            
            }
            
        }
        
        if(carry>0){
            ListNode *addOneDigit = new ListNode(carry);
            prev->next = addOneDigit;
        }
        
        return l1;
    }
};
