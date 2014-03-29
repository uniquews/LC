//
//  main.cpp
//  3Sum
//
//  Created by Shuai Wang on 3/29/14.
//  Copyright (c) 2014 Shuai Wang. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    static vector<vector<int>> threeSum(vector<int> &num){
        vector<vector<int>> result;
        sort(num.begin(), num.end());// in order to satisfy the ascending order
        if(num.size()==0) return result; //check boundary
        
        // trivial way O(N^3)
//        for(auto start=num.begin(); start<prev(prev(num.end())); start++){
//            int gap1= 0-*start;
//            for(auto mid = next(start); mid<prev(num.end()); mid++){
//                int gap2=gap1-*mid;
//                for(auto last = next(mid); last<num.end(); last++)
//                    if(gap2==*last)
//                        result.
//                        result.push_back({*start, *mid, *last});
//            }
//        }
        
        //sort and upper_bound deal with the duplicate records
        //O(N^2 * LogN)
//        for(auto start = num.begin(); start<prev(num.end(), 2); start = upper_bound(start, prev(num.end(), 2), *start)){
//            int gap1=0-*start;
//            for(auto mid = next(start); mid<prev(num.end()); mid = upper_bound(mid, prev(num.end()), *mid)){
//                int gap2 = gap1-*mid;
//                if(binary_search(next(mid),num.end(),gap2))
//                    result.push_back({*start, *mid, gap2});
//            }
//            
//            
//        }
        
        
        //O(N^2) without using set
        
        for(size_t i=0; i<num.size(); i++){
            if(i>0 && num[i]==num[i-1])
                continue;
            size_t mid = i+1;
            size_t end = num.size()-1;
            
            while(mid<end){
                int tempSum=num[i]+num[mid]+num[end];
                if(tempSum>0){
                    end--;
                }else if(tempSum<0){
                    mid++;
                }else{
                    result.push_back({num[i],num[mid],num[end]});
                    do{mid++;} while(num[mid]==num[mid-1] && mid<end);
                    
                    do{end--;} while (num[end]==num[end+1]&& mid<end);
                }
            
            }
            
      
        }
        
        return result;
    }
};


//-4 -1 -1 0 1 2



int main(int argc, const char * argv[])
{
    

    // insert code here...
    vector<int> num = {-1, 0, 1, 2, -1, -4};
    vector<int> temp;
   vector<vector<int>> result = Solution::threeSum(num);
    for(vector<vector<int>>::iterator it=result.begin(); it<result.end();it++){
        temp = *it;
        for(vector<int>::iterator it2 = temp.begin(); it2<temp.end();it2++){
            cout<< *it2<<" ";
        }
        cout<<endl;
    }
    return 0;
}

