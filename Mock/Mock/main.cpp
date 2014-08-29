//
//  main.cpp
//  Mock
//
//  Created by Shuai Wang on 8/26/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Starting Time: 10:22 am PST



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *intersection(ListNode *l1, ListNode *l2) {
        unordered_map<int, vector<ListNode *>> _map;
        ListNode dummy(INT_MIN);
        dummy.next = nullptr;
        ListNode *head = &dummy;
        if (l1 == nullptr || l2 == nullptr) {
            return dummy.next;
        }
        
        while (l1 != nullptr) {
            int val = l1 -> val;
            if (_map[val].size() == 0) {
                vector<ListNode *> listNodes;
                listNodes.push_back(l1);
                _map[val] = listNodes;
            } else {
                _map[val].push_back(l1);
            }
            
            l1 = l1 -> next;
        }
        
        
        while (l2 != nullptr) {
            int val = l2 -> val;
            if (_map[val].size() != 0) {
                ListNode *eachItem = new ListNode(l2->val);
                head ->next = eachItem;
                _map[val].pop_back();
                head = head -> next;
            }
            
            l2 = l2 -> next;
        }
        
        
        return dummy.next;
    }
    
};

static void input(){
    while(1) {
        cout<<"First lists:"<<endl;
        int sizeList1;
        cin>>sizeList1;
        ListNode *head1 = new ListNode(0);
        ListNode *ite1;
        ite1 = head1;
        while (sizeList1--) {
            int val;
            cin>>val;
            ListNode *tmp = new ListNode(val);
            ite1->next = tmp;
            ite1 = tmp;
        }
        
        
        cout<<"Second lists:"<<endl;
        int sizeList2;
        cin>>sizeList2;
        ListNode *head2 = new ListNode(0);
        ListNode *ite2;
        ite2 = head2;
        while (sizeList2--) {
            int val;
            cin>>val;
            ListNode *tmp = new ListNode(val);
            ite2->next = tmp;
            ite2 = tmp;
        }
        Solution su;
//        cout << su.intersection(head1->next, head2->next) -> val << endl;
        
        
        ListNode *result =su.intersection(head1->next, head2->next);
        
        while (result != nullptr) {
            cout << result -> val << " ";
            result = result -> next;
        }
        
    }
}


int main(int argc, const char * argv[])
{
    
    input();
    /*
    ListNode *l1 = new ListNode(1);
    ListNode *l1 = new ListNode(1);
//    ListNode *l2 = nullptr;
    
    ListNode *l2 = new ListNode(1);
     */
    
   
    return 0;
}



