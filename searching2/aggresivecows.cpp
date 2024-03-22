#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    bool issolutionpossible(int mid, int k, vector<int> &stalls)
    {
        int count=1;
        int pos=stalls[0];
        for(int i=0;i<stalls.size();i++)
        {
            if(stalls[i]-pos>=mid)
            {
                count++;
                if(count==k)
                {
                    return true;
                }
                pos=stalls[i];
            }
        }
        return false;
    }
public:
    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        int ans=-1;
        int low=0;
        int maxx=-1;
        int mid=0;
        for(int i=0;i<stalls.size();i++)
        {
            maxx=max(maxx,stalls[i]);
        }
        int high=maxx;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(issolutionpossible(mid,k,stalls))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};