#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int begin=0;
        int end=nums.size()-1;
        while(begin<end)
        {
            int mid=(begin+end)/2;
            if(nums[begin]<=nums[mid])
            {
              if(nums[begin]<nums[end])
              {
                end=mid-1;
              }
              else
              {
                begin=mid+1;
              }  
            }
            else
            {
                end=mid;
            }
        }
        return nums[begin]; 
    }
};