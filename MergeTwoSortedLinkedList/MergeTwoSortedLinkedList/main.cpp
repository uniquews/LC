//
//  main.cpp
//  MergeTwoSortedLinkedList
//
//  Created by Shuai Wang on 3/27/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

using namespace std;

class LinkList{
public:
    int val;
    LinkList *next;
    LinkList(int x):val(x), next(NULL){};
};



class Solution{
public:
    static  LinkList * merge(LinkList *l1, LinkList *l2){
        LinkList *p = new LinkList(-1);
        LinkList *q = p;
        for(;l1!=nullptr || l2!=nullptr;p=p->next){
            int l1_val = l1==nullptr?INT_MAX:l1->val;
            int l2_val = l2==nullptr?INT_MAX:l2->val;
            
            if(l1_val >l2_val){
                p->next = l2;
                l2=l2->next;
            }else{
                p->next = l1;
                l1=l1->next;
            }
        }
        
        return q->next;
    
    }

};


int main(int argc, const char * argv[])
{

    // insert code here...
    
    LinkList *a1 = new LinkList(1);
    LinkList *a2 = new LinkList(2);
    LinkList *a3 = new LinkList(3);
    LinkList *b1 = new LinkList(31);
    LinkList *b2 = new LinkList(32);
    LinkList *b3 = new LinkList(33);
    
    a1->next=a2;
    a2->next=a3;
    b1->next=b2;
    b2->next=b3;
    
    
   LinkList *p = Solution::merge(a1, b1);
    
    for(;p!=nullptr;p=p->next)
        cout<<p->val<<endl;
    //cout<<"okjjjjj"<<endl;
    
    return 0;
}

