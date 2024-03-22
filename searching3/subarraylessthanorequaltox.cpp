#include<bits/stdc++.h>
using namespace std;
bool ispossiblesolution(vector<int> arr,int mid,int s,int n)
{
    int sum=0;
    for(int i=0;i<mid;i++)
    {
        sum=sum+arr[i];
        if(sum>s)
        {
            return false;
        }
    }
    for(int i=0,j=mid;j<n;i++,j++)
    {
        sum=sum-arr[i];
        sum=sum+arr[j];
        if(sum>s)
        {
            return false;
        }
        
    }
    return true;
}
int main()
{
    int ans=0;
    vector<int> arr;
    int n;
    cin>>n;
    int temp;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        arr.push_back(temp);
        
    }
    int s;
    cin>>s;
    int low=0;
    int high=n;
   
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(ispossiblesolution(arr,mid,s,n))
        {
            ans=mid;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    cout<<ans;
    
}