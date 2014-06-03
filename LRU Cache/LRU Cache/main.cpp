//
//  main.cpp
//  LRU Cache
//
//  Created by Shuai Wang on 6/2/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

class LRUCache{
    
public:

    struct Node{
        Node * prev;
        Node * next;
        int value;
        int key;
        Node (Node *p, Node *n, int value, int key):prev(p), next(n), value(value), key(key){}
        Node (int value, int key):prev(nullptr), next(nullptr), value(value), key(key){}
        
    };
    
    
    map<int, Node *> map;
    int capacity;
    Node *head;
    Node * tail;
    
    
    //insert node at the tail of the link list
    void insertNode(Node *n){
        if(head==nullptr){
            head=n;
            tail=n;
            
        }else{
            if(tail==nullptr){
                tail=n;
            }else{
                tail->next=n;
                n->prev=tail;
                n->next=nullptr;
                tail=tail->next;
            }
        }
    }

    
    void removeNode(Node *n){
        if(head==nullptr)
            return;
        if(n==head){
            Node *temp = head->prev;
            temp->next=nullptr;
            head=temp;
            delete n;
            
        }else if(n==tail){
            Node *temp=n->next;
            temp->prev=nullptr;
            tail = temp;
            delete n;
        }else{
            n->prev->next = n->next;
            n->next->prev = n->prev;
            n->prev = nullptr;
            n->next= nullptr;
            delete n;
        }
    }
    
    // move current node to the tail of the linked list
    void moveNode(Node* node){
        if (tail==node){
            return;
        }else{
            if (node==head){
                node->next->prev = NULL;
                head = node->next;
                tail->next = node;
                node->prev = tail;
                tail=tail->next;
            }else{
                node->prev->next = node->next;
                node->next->prev = node->prev;
                tail->next = node;
                node->prev = tail;
                tail=tail->next;
            }
        }
    }
    ///////////////////////////////////////////////////////////////////////
    // get method
    ///////////////////////////////////////////////////////////////////////
    int get(int key) {
        if (map.find(key)==map.end()){
            return -1;
        }else{
            Node *tmp = map[key];
            moveNode(tmp);
            return map[key]->value;
        }
    }
    
    ///////////////////////////////////////////////////////////////////////
    // set method
    ///////////////////////////////////////////////////////////////////////
    void set(int key, int value) {
        if (map.find(key)!=map.end()){
            moveNode(map[key]);
            map[key]->value = value;
        }else{
            if (map.size()==capacity){
                map.erase(head->key);
                removeNode(head);
            }
            Node * node = new Node(key,value);
            map[key] = node;
            insertNode(node);
        }
    }
    
};






int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

