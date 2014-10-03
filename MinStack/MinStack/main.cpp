//
//  main.cpp
//  MinStack
//
//  Created by Shuai Wang on 4/2/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <stack>
#include <utility>

using namespace std;
class MinStack{
public:
    
    stack<pair<int,int>> *min=nullptr;
    
    //function
    bool empty();
    void push(int);
    void pop();
    int top();
    int MinTop();
    size_t size();
    
    int minNumber;
    
    
    MinStack(stack<pair<int,int>> *p = NULL){
        
        this->min = p;
        cout << "excute constructor" << endl;
    
    }
    
    
    ~MinStack(){
        delete min;
        cout << "excute destructor" << endl;
    }
    
    stack<pair<int,int>> & operator * () {
        return *min;
    }
    
    stack<pair<int,int>> * operator -> () {
        return min;
    }
};

bool MinStack::empty(){
    return this->min->empty();

}

void MinStack::push(int a){
    if(this->empty()==true){// directly push element into the stack
        
        this->minNumber=a;
        this->min->push(make_pair(a, a));
        
    }else{
        if(a>=this->minNumber){// keep the original minNumber
            this->min->push(make_pair(a, this->minNumber));
        }else{ // update a new minNumber
            this->minNumber = a;
            this->min->push(make_pair(a, minNumber));
        }
    }
    return;
}

void MinStack::pop(){
    this->min->pop();

}

int MinStack::top(){
    return this->min->top().first;

}

int MinStack::MinTop(){
    return this->min->top().second;
}


size_t MinStack:: size(){
    return this->min->size();
}



int main(int argc, const char * argv[])
{

    // insert code here...Ω
    
    MinStack minStack(new stack<pair<int,int>>());
    minStack.push(4);
    minStack.push(5);
    minStack.push(8);
    
    
    while (minStack.size() != 0) {
        cout <<"The top is "<< minStack.top()<<" ";
        cout<< "The min of the stack now is " << minStack.MinTop()<<" " << endl;
        minStack.pop();
    }
    

    
    return 0;
}

