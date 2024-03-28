class Solution {
public:

    int nthMagicalNumber(int n, int a, int b) {
        int modulo=1e9+7;
        long long ans=0;
        if(n==1)
        return min(a,b);
        else
        {
            long low=min(a,b);
            long l=lcm(a,b);
           long long high=n*l;
            while(low<=high)
            {
                long long mid=low+(high-low)/2;
                long long count=(mid/a)+(mid/b)-(mid/l);
                if(count==n)
                {
                   if(mid%a==0||mid%b==0){
                      ans=mid;
                      return mid%modulo;
                   }
      
                   else
                   {
                      high=mid-1;
                   }
                }
                else if(count>n)
                {
                    high=mid-1;
                }
                else
                {
                    //break;
                    low=mid+1;
                }

            }
        }
        return -1;
    }
}
