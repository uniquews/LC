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

private:
    struct Node {
        int val;
        Node *prev;
        Node *next;
        int key;
        
        Node (int key, int value) {
            this->key = key;
            this->val = value;
            this->prev = nullptr;
            this->next = nullptr;
        
        }
        
    
    };
    
    
    int capacity;
    unordered_map<int, Node *> hs;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    
    
    

public:
    
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (hs.find(key) == hs.end()) {
            return -1;
        }
        
        Node *current = hs[key];
        
        current->prev->next = current->next;
        current->next->prev = current->prev;
        
        moveToTail(current);
        return hs[key]->val;
        
    }
    
    void moveToTail(Node *current) {
        current->prev = tail->prev;
        tail->prev = current;
        current->prev->next = current;
        current->next = tail;
    }
    
    void set(int key, int value) {
        if (get(key) != -1) {
            hs[key]->val = value;
            return;
            
        }
        
        if (hs.size() == this->capacity) {
            hs.erase(head->next->key);
            head->next = head->next->next;
            head->next->prev = head;
        }
        
        Node *insert = new Node(key, value);
        hs[key] = insert;
        moveToTail(insert);
    }
};






int main(int argc, const char * argv[])
{
    LRUCache lcr(2);
    lcr.set(2, 1);
    lcr.set(1, 1);
    lcr.set(2, 3);
    lcr.set(4, 1);
    
    cout << lcr.get(1) << endl;
    cout << lcr.get(2) << endl;
    
    return 0;
}

