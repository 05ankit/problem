#include <bits/stdc++.h> 
using namespace std; 
int countRotations(vector<int> arr) 
{ 
    int low=0;
    int high=arr.size()-1; 
    if (high < low) 
        return 0;  
    if (high == low) 
        return low; 
    int mid = low + (high - low) / 2;  
    if (mid < high && arr[mid + 1] < arr[mid])
    { 
        return (mid + 1);
    } 
    if (mid > low && arr[mid] < arr[mid - 1])
    { 
        return mid;
    }  
    if (arr[high] > arr[mid]) 
    {
        high=mid-1;
    }     
    else
    {
        low=mid+1;
    }    
} 