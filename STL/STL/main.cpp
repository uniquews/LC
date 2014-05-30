//
//  main.cpp
//  STL
//
//  Created by Shuai Wang on 4/2/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
#include <list>

using namespace std;

class Solution{
public:
    static void solution(){
        list<int> *linkList=new list<int>();
        
        linkList->push_back(1);
        linkList->push_back(2);
        linkList->push_back(3);
        linkList->push_back(4);
        linkList->push_front(5);
        linkList->push_front(6);
        linkList->push_front(7);
        for(list<int>::iterator it=linkList->begin(); it!=linkList->end(); it++){
            cout<<*it;
        
        }
        cout << endl;
        linkList->sort();
        
        for(list<int>::iterator it=linkList->begin(); it!=linkList->end(); it++){
            cout<<*it;
            
        }
        cout << endl;
        
        deque<int> *deque1 = new deque<int>();
        deque1->push_back(11);
        deque<int>::iterator it = deque1->begin();
        
        
        it =deque1->insert(it,50);
        it =deque1->insert(it,51);
        //deque1->insert(it,52);
        it = deque1->insert(it,53);
//        it++;
        deque1->insert(it,54);
        for(it = deque1->begin();it!=deque1->end(); it++){
            cout << *it<< " ";
        }
        
        cout << endl;
    }

};


int main(int argc, const char * argv[])
{

    // insert code here...
    Solution::solution();
    cout << endl;
    return 0;
}

