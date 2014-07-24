//
//  main.cpp
//  Linked_List_Cycle
//
//  Created by Shuai Wang on 7/24/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr) return false;
        ListNode *first = head;
        ListNode *second = head->next;
        
        while(first!=nullptr &&second!=nullptr){
            if(first == second) return true; // cycle!!!!
            first = first->next;
            second = second->next;
            if(second == nullptr)
                return false;
            second = second->next;//do not code as second = second ->next ->next. Null pointer error!!!!!
        }
        
        return false;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

