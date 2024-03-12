#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        if(x==0)
        {
            return 0;
        }
        int ans=0;
        long long l=1,r=x;
        long long y=0;
        while(l<=r)
        {
            long long mid=(l+r)/2;
            y=mid*mid;
            if(y==x)
            {
                return mid;
            }
            if(y>x)
            {
                r=mid-1;
            }
            else
            {
                ans=mid;
                l=mid+1;
            }
        }
        return ans;
        
    }
};