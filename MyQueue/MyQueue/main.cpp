//
//  main.cpp
//  MyQueue
//
//  Created by Shuai Wang on 4/2/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <stack>

using  namespace std;

class MyQueue{
public:
    stack<int> *frontStack=nullptr;
    stack<int> *backStack=nullptr;
    
    bool empty();
    size_t size();
    void push_back(int);
    void pop_back();
    void push_front(int);
    void pop_front();
    int At(size_t i);
    int top();
    
    
    MyQueue(){
        this->frontStack=new stack<int>();
        this->backStack=new stack<int>();
    
    }
    
    ~MyQueue(){
        this->frontStack=nullptr;
        this->backStack=nullptr;
    }

};

bool MyQueue::top(){
    

}


bool MyQueue::empty(){
    if(this->frontStack->empty()){ // front stack is empty, we need to check if the back stack is also empty
        if(this->backStack->empty()){
            return true;
        }else{
            return false;
        }
    }else{//if the front stack is alreay not empty, then we return false
        return false;
    
    }
}


size_t MyQueue::size(){
    if(this->frontStack->empty()){
        if(this->backStack->empty()){
            return 0;
        }else{
            return this->backStack->size();
        }
    
    }else{
        return this->frontStack->size();
    }

}



void MyQueue::push_back(int a){
    if(this->empty()){//if myQueue is empty, then we directly add element into the back stack
        this->backStack->push(a);
        
    }else{
        if(this->backStack->empty()){ // the myQueue is not empty but the backstack is empty, that means all elements are int the frontstack
            while(!this->frontStack->empty()){// switch the elements from the frontstack to the backstack
                int tempNumber = this->frontStack->top();
                this->backStack->push(tempNumber);
                this->frontStack->pop();
            }
        
            this->backStack->push(a);
        }else{
            // push a into the backstack
            this->backStack->push(a);
        }
    
    }
    
    return;

}


void MyQueue::pop_back(){
    if(this->empty()){
        return;
    }
    if(this->backStack->empty()){
        while(this->frontStack->empty()){
            int tempNumber = this->frontStack->top();
            this->frontStack->pop();
            this->backStack->push(tempNumber);
        }
        this->backStack->pop();
    }else{
        this->backStack->pop();
    
    }
    return;

}



void MyQueue::push_front(int a){
    if(this->empty()){
        this->frontStack->push(a);
        return;
    }else{
        if(this->frontStack->empty()){
            while(this->backStack->empty()){
                int tempNumber = this->backStack->top();
                this->frontStack->push(tempNumber);
                this->backStack->pop();
            
            }
            this->frontStack->push(a);
        }else{
            this->frontStack->push(a);
        
        }
        return;
    
    }

}


void MyQueue:: pop_front(){
    if(this->empty()){
        return;
    
    }else{
        if(this->frontStack->empty()){
            while(this->backStack->empty()){
                int tempNumber = this->backStack->top();
                this->frontStack->push(tempNumber);
                this->backStack->pop();
            }
            this->frontStack->pop();
        
        }else{
            this->frontStack->pop();
        }
    
    }
    


}



int MyQueue::At(size_t i){
    if(this->empty()){
        return INT_MIN;
    }else if(i>this->size()){
        return INT_MIN;
    } else{
        if(this->frontStack->empty()){// fullfill the front stack
            while(this->backStack->empty()){
                int tempNumber = this->backStack->top();
                this->frontStack->push(tempNumber);
                this->backStack->pop();
            }
            int tempNumber;
            for(size_t m=0; m<=i;m++){
                int tempNumber = this->frontStack->top();
                this->backStack->push(tempNumber);
                this->frontStack->pop();
            }
            
            // swith all the remaining values to the backStack
            while(this->frontStack->empty()){
                int tt = this->backStack->top();
                this->backStack->push(tt);
                this->backStack->pop();
            
            }
            
            return tempNumber;
        }else{
            int tempNumber;
            for(size_t m=0; m<=i;m++){
                int tempNumber = this->frontStack->top();
                this->backStack->push(tempNumber);
                this->frontStack->pop();
            }
            // swith all the remaining values to the backStack
            while(this->frontStack->empty()){
                int tt = this->backStack->top();
                this->backStack->push(tt);
                this->backStack->pop();
                
            }
            
            return tempNumber;
        }
    }

}


int main(int argc, const char * argv[])
{

    // insert code here...
    MyQueue *myQueue = new MyQueue();
    myQueue->push_front(4);
    myQueue->push_front(5);
    myQueue->push_front(6);
    myQueue->push_front(7);
    myQueue->push_front(8);
    myQueue->push_front(9);
    myQueue->push_front(10);
    myQueue->push_back(30);
    myQueue->push_back(31);
    myQueue->push_back(32);
    myQueue->push_back(33);
    myQueue->push_back(34);
    
    cout<< myQueue->top();
//    
//    for(size_t i=0; i<myQueue->size(); i++){
//    
//            cout << myQueue->At(i)<<" ";
//    }
    
    return 0;
}

