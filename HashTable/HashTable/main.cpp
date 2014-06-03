//
//  main.cpp
//  HashTable
//
//  Created by Shuai Wang on 6/3/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class dataPair{

public:
    int key;
    int value;
};

class HashTable{
    vector<dataPair> v;
    int numel=0;
    int capacity=5;
    
public:
    HashTable(int cap);
    int hash(dataPair &dp);
    int rehash(int &dp);
    int insert(dataPair &dp);
    int remove(int &id);
    int retrieve(int &id);
    void output();
    void showAvailableCapacity();
    
    void test();

};


void HashTable::test(){
    vector<dataPair> :: const_iterator it = this->v.begin();
    for(; it!=this->v.end(); it++){
    
        std::cout << it->key<<" and its value "<< it->value<<std::endl;
    }


}


HashTable::HashTable(int capacity){
    this->numel=0;
    dataPair dTemp;
    dTemp.key=-1;
    dTemp.value=0;
    for(int i=0; i<this->capacity; i++){
       
        v.push_back(dTemp);
    }

}

int HashTable::hash(dataPair &dp){
    int temp = (dp.key)%capacity;
    if(this->v[temp].key==-1 ||this->v[temp].key==-2){
        this->v[temp].key = dp.key;
        this->v[temp].value = dp.value;
        this->numel++;
    }else{
        //call rehash
        int flag=rehash(dp.key);
        int tempKey = dp.key;
        while(1){
            tempKey++;
            if(this->v[flag].key==-1 || this->v[flag].key==-2){
                this->v[flag].key=dp.key;
                this->v[flag].value = dp.value;
                this->numel++;
                break;
            }
            
            flag=rehash(tempKey);
        }
        
    
    }
    
    return 0;
}

int HashTable::insert(dataPair &dp){
    if(this->capacity==this->numel)
        return -1;
    hash(dp);
  
    return 0;
}


int HashTable::remove(int &id){
    int temp=id%this->capacity;
    int times=0;
    bool find=false;
    int tempId=id;
    while(times<this->capacity){
        if(this->v[temp].key!=id){
            
            temp = (tempId++)%this->capacity;
            times++;
            
        }else{
            find=true;
            this->v[temp].key=-2;
            this->v[temp].value=0;
            this->numel--;
            break;
        }
        
    }
    
    if(!find){
        std::cout <<"Cannot find the removed id"<<std::endl;
        return -1;
    }
    

    return 0;
}


int HashTable::retrieve(int &id){
    int temp=id%this->capacity;
    int times=0;
    bool find=false;
    int result=0;
    int tempId=id;
    while(times<this->capacity){
        if(this->v[temp].key!=id){
            temp = (tempId++)%this->capacity;
            times++;
            
        }else{
            find=true;
            result=this->v[temp].value;
            break;
        }
        
    }
    
    if(!find){
        std::cout <<"Cannot find the retrieved id"<<std::endl;
        return -1;
    }
    return result;
}


int HashTable::rehash(int &key){
    int tempkey = key;
    return(tempkey)%(this->capacity);
    
}


void HashTable::showAvailableCapacity(){

    std::cout<<" Empty: " <<this->capacity - this->numel <<endl;
}


void HashTable::output(){

    vector<dataPair> :: const_iterator it;
    it = this->v.begin();
    for(;it!=this->v.end(); it++){
        std::cout<< it->value << std::endl;
    }
    return;
}

int main(int argc, const char * argv[])
{

    // insert code here...
    
    HashTable hashTable(5);
//    hashTable.test();
    
    dataPair d;
    d.key = 27;
    d.value = 270;
    
    hashTable.insert(d);
    hashTable.output();
    
    std::cout<<endl;
    
    d.key = 99;
    d.value = 990;
    hashTable.insert(d);
    hashTable.output();
    
    
    std::cout<<endl;
    
    d.key = 32;
    d.value = 320;
    hashTable.insert(d);
    hashTable.output();
    
    
    std::cout<<endl;
    d.key = 77;
    d.value = 770;
    hashTable.insert(d);
    hashTable.output();

    std::cout<<endl;
    hashTable.showAvailableCapacity();
    
    
    
    //retrieve data
    int id = 270;
    int val = hashTable.retrieve(id);
    cout << endl;
    cout << "Retrieving ... " << endl;
    cout << "hashtable[" << id<< "]=" << val << endl;
    cout << endl;
    
    
    //delete element
    d.key = 77;

    hashTable.remove(d.key);
    hashTable.output();
    
    return 0;
}

