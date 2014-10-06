//
//  main.cpp
//  Hash Map
//
//  Created by Shuai Wang on 10/3/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;


class Hash_Map {

public:
    
    
    vector<pair<int, int>> table;
    size_t size;
    size_t capacity;
    
    Hash_Map();
    int insert(pair<int, int>);
    int hash(pair<int, int>);
    int remove(int id);
    size_t showAvailablity();
    int getCapacity();
};


Hash_Map :: Hash_Map () {
    this->size = 256;



}




int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

