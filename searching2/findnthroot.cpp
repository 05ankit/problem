#include<bits/stdc++.h>
using namespace std;
int nthroot(int n,int m)
{
    int low=n;
    int high=m;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(pow(mid,n)==m)
        {
            return mid;
        }
        else if(pow(mid,n)>m)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }

    }
    return -1;
}