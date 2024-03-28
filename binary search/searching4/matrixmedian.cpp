int upperbound(vector<int> &arr,int x,int n)
{
    int low=0;
    int high=n-1;
    int ans=n;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]>x)
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
int countsmallorequal(vetcor<vector<int>> &matrix,int n,int m,int x)
{
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        cnt+= upperbound(matrix[i],x,m);
    }
    return cnt;
}
int median(vector<vector<int>> &matrix,int m,int n)
{
    int low=INT_MAX;
    int high=INT_MIN;
    n=matrix.size();
    m=matrix[0].size();
    for(int i=0;i<n;i++)
    {
        low=min(low,matrix[i][0]);
        high=max(high,matrix[i][m-1]);
    }
    int req=(n*m)/2;
    while(low<=high)
    {
        int mid=(low+high)/2;
        int smallorequal=countsmallorequal(matrix,n,m,mid);
        if(smallorequal<=req) low=mid+1;
        else{
            high=mid+1;
        }
    }
    return low;
}
