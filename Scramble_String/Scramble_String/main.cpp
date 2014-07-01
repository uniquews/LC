//
//  main.cpp
//  Scramble_String
//
//  Created by Shuai Wang on 6/28/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
//    bool isScramble(string s1, string s2) {
//        if(s1.length()==0 && s2.length()==0)
//            return true;
//        return dfs(s1.begin(), s1.end(), s2.begin());
//    }

    
// small test set is ok; cannot pass the large set

//    bool dfs(string::iterator first1, string::iterator last1, string::iterator first2){
//        auto length = distance(first1, last1);
//        auto last2 = next(first2, length);
//        if(length == 1) return *first1 == *first2;
//        
//        
//        for(int i=1; i<length; i++){
//            if ((dfs(first1, first1+i, first2) && dfs(first1+i, last1, first2+i)) || (dfs(first1, first1+i, last2-i) && dfs(first1+i, last1, first2)))
//                return true;
//        
//        }
//        return false;
//    }
    
    
// add cut edge. check all char in string
//    bool dfs(string:: iterator first1, string:: iterator last1, string::iterator first2){
//        
//        auto length = distance(first1, last1);
//        auto last2= next(first2, length);
//        
//        if(length == 1) return *first1 == *first2;
//        
//        int A[26] = {0};
//        for(int i=0; i< length; i++) A[*(first1+i)-'a']++;
//        for(int i = 0; i<length; i++) A[*(first2+i)-'a']--;
//        
//        for(int i=0; i< 26; i++) if(A[i]!=0) return false;
//        
//        for(int i=1; i<length; i++){
//            if ((dfs(first1, first1+i, first2) && dfs(first1+i, last1, first2+i)) || (dfs(first1, first1+i, last2-i) && dfs(first1+i, last1, first2)))
//                return true;
//            
//        }
//        return false;
//    
//    
//    }
    typedef string::iterator Iterator;
    typedef tuple<Iterator, Iterator, Iterator> Key;
    unordered_map<Key, bool> cache;
    
    bool isScramble(string s1, string s2) {
        cache.clear();
        return dfs(s1.begin(), s1.end(), s2.begin());
       
    }
    
    
    bool dfs(Iterator first1, Iterator last1, Iterator first2){
        auto length = distance(first1, last1);
        auto last2 = next(first2, length);
        
        if(length == 1) return *first1 == *first2;
        
        
        
        for(int i=1; i<length; i++){
            if((cacheCheck(first1, first1+i, first2) && cacheCheck(first+i, last1, first2+i)) || (cacheCheck(first1, first1+i, last1-i) && cacheCheck(first1+i, last1, first2)))
                return true;
            
        }
        
        return false;
    
    }
    
    
    
    bool cacheCheck(Iterator it1, Iterator it2, Iterator it3){
        auto key  = make_tuple(it1, it2, it3);
        if(find(cache.begin(), cache.end(), key)!=cache.end())
            return cache[key];
        else{
            return cache[key]= dfs(it1, it2, it3);
        }
    
    }
    
};



int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

