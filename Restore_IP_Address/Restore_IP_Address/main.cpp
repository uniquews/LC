//
//  main.cpp
//  Restore_IP_Address
//
//  Created by Shuai Wang on 6/22/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    vector<string> restoreIpAddresses(string s) {
//        vector<string> result;
//        
//        string str;
//        int start = 0;
//        int num = 0;
//        str.clear();
//        dfs(s, start, str, result, num);
//        return result;
//    }
//    
//    void dfs(string &s, int start, string &str, vector<string> &result, int &num){
//        if(num == 4 && start == (int)s.size()){
//            result.push_back(str);
//            return;
//        }else if(num == 4){
//            return;
//        }else{
//            
//            int strSize = (int)s.length() - start;
//            string tempStr = s.substr(start, strSize);
//            for(int i = 1; i<= 3; i++){
//                
//                string tempCut = tempStr.substr(0, i);
//                if(tempCut[0] == '0' && tempCut.size()>1){
//                    continue;
//                }else{
//                    if(atoi(tempCut.c_str())>=0 && atoi(tempCut.c_str())<=255){
//                        num++;
//                        string store = str;
//                        if(num!=4)
//                            str.append(tempCut+".");
//                        else
//                            str.append(tempCut);
//                        if(start + i <= s.length()){
//                            dfs(s, start+i, str, result, num);
//                        }else{
//                            num--;
//                            str = store;
//                            break;
//                        }
//                        
//                        num--;
//                        str = store;
//                        
//                    }
//                
//                }
//               
//            }
//        
//        
//        }
//        
//    
//    }
//};

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() == 0) {
            return vector<string> {};
        }
        
        vector<string> result;
        string str = "";
        
        dfs(s, 0, result, str, 0);
        return result;
    }
    
    void dfs(string s, int start, vector<string> &result, string &str, int position) {
        if (start == s.size() && position == 4) {
            result.push_back(str);
            return;
        } else if (start != s.size() && position == 4){
            return;
        } else if (start == s.size() && position != 4) {
            return;
        } else {
            if (s[start] == '0') {
                string origin = str;
                string tmp = s.substr(start, 1);
                str += tmp;
                if (position != 3) {
                    str += '.';
                }
                dfs (s, start + 1, result, str, position + 1);
                str = origin;
            } else {
                for (int i = 1; i <= 3; i++) {
                    string origin = str;
                    if (start + i - 1 <= s.size() - 1) {
                        string tmp = s.substr(start, i);
                        int val = stoi(tmp);
                        if (val > 0 && val <= 255) {
                            str += tmp;
                            if (position != 3) {
                                str += '.';
                            }

                            dfs (s, start + i, result, str, position + 1);
                            str = origin;
                        } else {
                            continue;
                        }
                    
                    }

                }
            }
        }
        
        return;
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    Solution s;
    vector<string> result = s.restoreIpAddresses("0000");
    vector<string>::iterator it = result.begin();
    for(; it!=result.end(); it++){
        cout << *it << " ";
    
    }
    
    cout << endl;
    
    
    
    std::cout << "Hello, World!\n";
    return 0;
}

