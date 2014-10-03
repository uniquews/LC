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
    void push(int);
    void pop();
    int At(size_t i);
    int top();
    
    
    MyQueue(){
        this->frontStack=new stack<int>();
        this->backStack=new stack<int>();
    
    }
    
    ~MyQueue(){
        delete frontStack;
        delete backStack;
        this->frontStack=nullptr;
        this->backStack=nullptr;
    }

};




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


void MyQueue::push(int num) {
    if (this->frontStack->empty() && this->backStack->empty()) {
        this->backStack->push(num);
        return;
    } else if (this->backStack->empty()) {
        
        while (!this->frontStack->empty()) {
            int tmp = this->frontStack->top();
            this->frontStack->pop();
            this->backStack->push(tmp);
        }
        
        this->backStack->push(num);
        return;
    
    } else {
        this->backStack->push(num);
        return;
        
    }
}


void MyQueue:: pop() {
    if (this->backStack->empty() && this->frontStack->empty()) {
        return;
    } else if (this->frontStack->empty()) {
        while (!this->backStack->empty()) {
            int tmp = this->backStack->top();
            this->backStack->pop();
            this->frontStack->push(tmp);
            
        }
        this->frontStack->pop();
        return;
    
    } else {
        this->frontStack->pop();
        return;

    }
    

}



int MyQueue:: top() {
    if (this->backStack->empty() && this->frontStack->empty()) {
        return INT_MIN;
    } else if (this->frontStack->empty()) {
        while (!this->backStack->empty()) {
            int tmp = this->backStack->top();
            this->backStack->pop();
            this->frontStack->push(tmp);
            
        }
        
        return this->frontStack->top();
        
    } else {
        
        return this->frontStack->top();
        
    }


}


//int MyQueue::At(size_t i){
//    if(this->empty()){
//        return INT_MIN;
//    }else if(i>this->size()){
//        return INT_MIN;
//    } else{
//        if(this->frontStack->empty()){// fullfill the front stack
//            while(this->backStack->empty()){
//                int tempNumber = this->backStack->top();
//                this->frontStack->push(tempNumber);
//                this->backStack->pop();
//            }
//            int tempNumber;
//            for(size_t m=0; m<=i;m++){
//                int tempNumber = this->frontStack->top();
//                this->backStack->push(tempNumber);
//                this->frontStack->pop();
//            }
//            
//            // swith all the remaining values to the backStack
//            while(this->frontStack->empty()){
//                int tt = this->backStack->top();
//                this->backStack->push(tt);
//                this->backStack->pop();
//            
//            }
//            
//            return tempNumber;
//        }else{
//            int tempNumber;
//            for(size_t m=0; m<=i;m++){
//                int tempNumber = this->frontStack->top();
//                this->backStack->push(tempNumber);
//                this->frontStack->pop();
//            }
//            // swith all the remaining values to the backStack
//            while(this->frontStack->empty()){
//                int tt = this->backStack->top();
//                this->backStack->push(tt);
//                this->backStack->pop();
//                
//            }
//            
//            return tempNumber;
//        }
//    }
//
//}


int main(int argc, const char * argv[])
{

    // insert code here...
    MyQueue *myQueue = new MyQueue();
    myQueue->push(4);
    myQueue->push(5);
    myQueue->push(6);
    myQueue->push(7);
    myQueue->push(8);
    myQueue->push(9);
    myQueue->push(10);
    myQueue->push(30);
    myQueue->push(31);
    myQueue->push(32);
    myQueue->push(33);
    myQueue->push(34);
    
    cout<< myQueue->top() << endl;
    myQueue->pop();
    cout<< myQueue->top() << endl;
    myQueue->push(100);
    cout<< myQueue->top() << endl;
//    
//    for(size_t i=0; i<myQueue->size(); i++){
//    
//            cout << myQueue->At(i)<<" ";
//    }
    
    return 0;
}

