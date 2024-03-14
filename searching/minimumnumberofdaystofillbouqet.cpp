#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool issolutionpossible(vector<int>& bloomDay, int m,int mid, int k)
    {
        int bouqet=0;
        int count=0;
        for(int i=0;i<bloomDay.size();i++)
        {
            count++;
             if(bloomDay[i]>mid)
             {
                count=0;
             }
             if(count==k)
             {
                bouqet++;
                count=0;
             }
        }
        return bouqet>=m;
    }     
public:
    int minDays(vector<int>& bloomDay, long m, long k) {
        int maxx=0;
        int minn=0;
        int ans=0;
        long long mul=m*k;
        for(int i=0;i<bloomDay.size();i++)
        {
            maxx=max(bloomDay[i],maxx);
            minn=min(bloomDay[i],minn);
        }
        int low=minn;
        int high=maxx;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(issolutionpossible(bloomDay,m,mid,k))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        if(bloomDay.size()<mul)
        {
            return -1;
        }
        else
        {
            return ans;
        }
        
    }
};