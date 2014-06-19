//
//  main.cpp
//  WordLadder2
//
//  Created by Shuai Wang on 6/19/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        
        int level = 0;
        
        vector<string> stringVec;
        vector<string> nextLevel;
        unordered_map<string, vector<string>> father;
        vector<vector<string>> result;
        vector<string> eachResultInSameLevel;
        stringVec.push_back(start);
        
        unordered_set<string> visited;
        visited.insert(start);
        
        while(!stringVec.empty()){
            
            if(find(stringVec.begin(), stringVec.end(), end)!=stringVec.end())
                return result;
            
            for(auto current: stringVec)
                visited.insert(current);
            
            
            while(!stringVec.empty()){
                string temp = stringVec.back();
                stringVec.pop_back();
                
                for(int i=0;i<temp.size(); i++){
                    for(char tri = 'a'; tri <='z';tri++){
                        
                        string newString;
                        newString = temp;
                        
                        if(tri == newString[i]) continue;
                        
                        newString[i]=tri;
                        
                        if(newString == end){
                            father[newString].push_back(temp);
                            //push to the result
                            eachResultInSameLevel.push_back(newString);
                             getEachResultInOneLevel(father, newString, result, eachResultInSameLevel);
//                            result.push_back(eachResultInSameLevel);
                            father.erase(newString);
                            eachResultInSameLevel.pop_back();
                            nextLevel.clear();
                            break; // cannot be replaced by other char
                        }
                        
                        if((dict.find(newString)!=dict.end() && visited.count(newString)==0)){
                            
                            if(find(nextLevel.begin(), nextLevel.end(),newString)==nextLevel.end()){
                                nextLevel.push_back(newString);
                                
                            }
                            father[newString].push_back(temp);
                            
//                            visited.insert(newString);
                        }
                        
                        
                        newString.clear();
                        
                        
                    }
                }
            }
            
            if(!nextLevel.empty()){
                level++;
                
            }
            
            stringVec = nextLevel;
            nextLevel.clear();
            
        }
        
        return result;
        
    }
    
    
    
    
    void getEachResultInOneLevel(unordered_map<string, vector<string>> &m, string newString, vector<vector<string>> &resultAbov, vector<string> &result){
        
//        result.push_back(newString);

        unordered_map<string, vector<string>>::iterator got =m.find(newString);
        
        
        
        if(got == m.end()){
            
            reverse(result.begin(), result.end());
            
            resultAbov.push_back(result);
            
            reverse(result.begin(), result.end());
            
            return;
        
        }else{
         
            vector<string> temp = got->second;
            for(auto each: temp){
                result.push_back(each);
            
                getEachResultInOneLevel(m, each, resultAbov, result);
                result.pop_back();
                
            }
            

            return;
        
        }

    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
//    unordered_map<string, string> m = {{"hot", "hit"},
//        {"dot", "hot"},
//        {"dog", "dot"},
//        {"cog", "dog"}
//    };
//    
//    string newString = "cog";
    
    
    
//    string start = "hit";
//    string end = "cog";
//    unordered_set<string>  dict = {"hot","dot","dog","lot","log"};
    
    string start = "red";
    string end = "tax";
    unordered_set<string>  dict = {"ted","tex","red","tax","tad","den","rex","pee"};
    
//    string start = "a";
//    string end = "c";
//    unordered_set<string>  dict = {"a","b","c"};
    
    
    Solution s;
    vector<vector<string>> result = s.findLadders(start, end, dict);
    
    vector<vector<string>> :: iterator it = result.begin();
    
    for(; it!=result.end(); it++){
        vector<string> :: iterator it2 = it->begin();
        for(; it2!= it->end(); it2++){
        
            cout << *it2 <<" ";
        }
        cout << endl;
    
    }
    
    
    
    
    
//    s.getEachResultInOneLevel(m, newString);
    return 0;
}

