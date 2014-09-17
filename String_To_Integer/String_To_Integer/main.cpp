//
//  main.cpp
//  String_To_Integer
//
//  Created by Shuai Wang on 7/7/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

//class Solution {
//public:
//    int atoi(const char *str) {
//        int i = 0;
//        int length = strlen(str);
//        int sign = 1;
//        int result = 0;
//        
//        while(str[i]==' ') {i++;}
//        
//        if(str[i] == '+'){ // e.g.: +-2
//            if(str[i+1] == '+' || str[i+1]=='-')
//                return 0;
//            else
//                i++;
//            
//        }
//        if(str[i] == '-') {
//            if(str[i+1] == '-' || str[i+1] == '+')
//                return 0;
//            else{
//                sign = -1;
//                i++;
//            }
//        }
//        
//        for(int j = i; j< length; j++){
//            if(str[j] == ' ') break;
//            if(str[j] <'0' || str[j] >'9')
//                break;
//            if(INT_MAX/10<result || INT_MAX/10==result && INT_MAX%10<(str[j]-'0')){
//                return sign == -1? INT_MIN: INT_MAX;
//            }
//            
//            result = result*10 + (str[j]-'0');
//        }
//        
//        return result*sign;
//    }
//};

class Solution {
public:
    int atoi(const char *str) {
        int i = 0;
        int sign = 1;
        int length = strlen(str);
        int result = 0;
        
        while (str[i] == ' ') {
            i++;
        }
        
        if (str[i] == '+') {
            if (str[i + 1] == '+' || str[i + 1] == '-') {
                return 0;
            } else {
                i++;
            }
        }
        
        if (str[i] == '-') {
            if (str[i + 1] == '+' || str[i + 1] == '-') {
                return 0;
            } else {
                sign = -1;
                i++;
            }
        }
        
        for (int j = i; j < length; j++) {
            if (str[j] == ' ') {
                break;
            }
            
            if (str[j] < '0' || str[j] > '9') {
                break;
            }
            
            if (INT_MAX / 10 < result || (INT_MAX / 10 == result && str[j] > INT_MAX % 10 )) {
                return sign == -1 ? INT_MIN : INT_MAX;
            }
            
            result = result * 10 + (str[j] - '0');
        }
        
        return result;
    }
};




int main(int argc, const char * argv[])
{

    char *s = "+-2";
    Solution su;
    su.atoi(s);
    
    return 0;
}

