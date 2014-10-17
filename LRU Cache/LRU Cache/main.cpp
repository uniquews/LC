//
//  main.cpp
//  LRU Cache
//
//  Created by Shuai Wang on 6/2/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <unordered_map>

using namespace std;


class LRUCache{
public:
    
    struct Node {
        int key;
        int value;
        Node *next;
        Node *prev;
        
        Node (int key, int value) {
            this->key = key;
            this->value = value;
            this->prev = nullptr;
            this->next = nullptr;
        }
    };
    
    int capacity;
    unordered_map<int, Node*> hashMap;
    Node *head;
    Node *tail;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        
        head->next = tail;
        head->prev = nullptr;
        tail->prev = head;
        tail->next = nullptr;
    }
    
    int get(int key) {
        if (hashMap.find(key) == hashMap.end()) {
            return -1;
        }
        
        Node *cur = hashMap[key];
        Node *prevNode = cur->prev;
        Node *nextNode = cur->next;
        
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        
        moveToTail(cur);
        return cur->value;
    }
    
    void moveToTail(Node *cur) {
        cur->next = tail;
        cur->prev = tail->prev;
        cur->prev->next = cur;
        tail->prev = cur;
        return;
    }
    
    void set(int key, int value) {
        if (get(key) != -1) {
            hashMap[key]->value = value;
            return;
        }
        
        if (hashMap.size() == capacity) {
            Node *old = head->next;
            int oldKey = old->key;
            hashMap.erase(oldKey);
            head->next = old->next;
            old->next->prev = head;
        }
        
        
        Node *newNode = new Node(key, value);
        hashMap[key] = newNode;
        moveToTail(newNode);
        
        return;
    }
};




int main(int argc, const char * argv[])
{
//    LRUCache lcr(2);
//    lcr.set(2, 1);
//    lcr.set(1, 1);
//    lcr.set(2, 3);
//    lcr.set(4, 1);
    
    LRUCache lcr(1);
    lcr.set(2, 1);
    cout << lcr.get(2) << endl;

    lcr.set(3, 2);
    cout << lcr.get(2) << endl;
    cout << lcr.get(3) << endl;
   
    return 0;
}

