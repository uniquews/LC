//
//  main.cpp
//  Rotate_LIst
//
//  Created by Shuai Wang on 7/6/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == nullptr || k==0)
            return head;
        ListNode *cur  =head;
        int length = 1;
        while(cur->next){
            cur = cur->next;
            length++;
        }
        
        cur->next = head; // link the end and the start
        int index = length-k%length;
        
        for(int i=0; i< index; i++){
            cur = cur->next;
        }
        
        head = cur->next;
        cur->next = nullptr;
        return head;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

