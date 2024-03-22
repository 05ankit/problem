#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size() - 1;
        while (begin <= end) {
            int mid = (begin + end) / 2;
            if (nums[mid] == target) 
            {
                return mid;
            }
            else if (nums[begin] <=nums[mid]) // for left part
            {
                if (nums[begin] <=target) 
                {
                    if (nums[mid] < target) 
                    {
                        begin=mid+1;
                    } 
                    else 
                    {
                        end=mid-1;
                    }
                } 
                else
                {
                    if(nums[mid] < target) 
                    {
                        end = mid - 1;
                    } 
                    else 
                    {
                        begin = mid + 1;
                    }
                }
            } 
            else 
            {
                if(nums[begin]<=target) 
                {
                    end = mid - 1;
                } 
                else 
                {
                    if(nums[mid] < target) 
                    {
                        begin = mid + 1;
                    } 
                    else 
                    {
                        end= mid - 1;
                    }
                }
            }
        }
        
        return -1;
    }
};