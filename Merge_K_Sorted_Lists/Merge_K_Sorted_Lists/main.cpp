//
//  main.cpp
//  Merge_K_Sorted_Lists
//
//  Created by Shuai Wang on 7/13/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.size()==0) return nullptr;
        ListNode *p = lists[0];
        
        // for(int i=1; i<lists.size(); i++){
        //     p = mergeTwoLists(p, list[i]);
        // }
        
        for(int i=1; i<lists.size();i++){
            p = mergeTwoLists(p,lists[i]);
        }
        
        return p;
    }
    
    
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode head(-1);
        for(ListNode *p = &head; l1!=nullptr || l2!=nullptr; p = p->next){
            int val1 = l1 == nullptr?INT_MAX: l1->val;
            int val2 = l2 == nullptr?INT_MAX: l2->val;
            if(val1 >=val2){
                p->next = l2;
                l2 = l2->next;
            }else{
                p->next = l1;
                l1 = l1->next;
            }
        }
        
        return head.next;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

