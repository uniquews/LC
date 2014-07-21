//
//  main.cpp
//  Convert_Sort_Array_To_BST
//
//  Created by Shuai Wang on 7/20/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return divide(num.begin(), num.end());
        
    }
    
    template <typename InputIterator>
    TreeNode * divide(InputIterator start, InputIterator end){
        auto length = distance(start, end);
        if(length==0) return nullptr;
        if(length==1) return new TreeNode(*start);
        
        auto mid = start+length/2;
        auto root = new TreeNode(*mid);
        root->left = divide(start, mid);
        root->right = divide(mid+1, end);
    }
};

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

