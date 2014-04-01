//
//  File.c
//  test_copy
//
//  Created by Shuai Wang on 3/31/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <stdio.h>
//struct str{
//    int len;
//    char s[0];
//};
//
//struct foo{
//    struct str *a;
//};

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int main(int argc, char **argv){
    int a = 8;
    int b = 7;
    int *m = &a;
    int *n = &b;
    swap(m,n);
    return 0;
}