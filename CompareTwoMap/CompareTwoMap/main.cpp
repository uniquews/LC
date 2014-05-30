//
//  main.cpp
//  CompareTwoMap
//
//  Created by Shuai Wang on 4/2/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;


int main(int argc, const char * argv[])
{

    // insert code here...
    
    std::multimap<char,int> mymm;
    
    mymm.insert (pair<char,int>('x',10));
    mymm.insert (pair<char,int>('y',20));
    mymm.insert (pair<char,int>('z',30));
    mymm.insert (pair<char,int>('z',40));
    
    //std::multimap<char,int>::iterator it = mymm.find('x');
    //mymm.erase (it);
    //mymm.erase (mymm.find('z'));
    
    // print content:
    std::cout << "elements in mymm:" << '\n';
    std::cout << "y => " << mymm.find('y')->second << '\n';
    std::cout << "z => " << mymm.find('z')->second << '\n';
    return 0;
}

