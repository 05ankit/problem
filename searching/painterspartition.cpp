#include<bits/stdc++.h>
using namespace std;
bool ispossiblesolution(vector<int> &boards,int k,int mid)
{
    int count=1;
    int sum=0;
    for(int i=0;i<boards.size();i++)
    {
        sum=sum+boards[i];
        if(boards[i]>mid)
        return false;
        if(sum>mid)
        {
            count++; 
            sum=boards[i];
        }
    }
    if (count > k) 
    {
        return false;
    }
    else{
        return true;
    }
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    int low=0;
    int high=0;
    int ans=0;
    for(int i=0;i<boards.size();i++)
    {
        high=high+boards[i];
    }
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(ispossiblesolution(boards,k,mid))
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return ans;
}