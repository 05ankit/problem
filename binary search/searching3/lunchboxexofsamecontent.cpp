#include <iostream>
#include<vector>
#include<map>
using namespace std;
bool check(map<int,int> m,int a,int l)
{
    for(auto x:m)
    {
        if(x.second>=l)
        {
            a=a-(x.second)/l;
        }
    }
    return a<=0;
    
}
int main()
{
    int a,n;
    cin>>a>>n;
    vector<int> item(n);
    int i=1,j=0;
    for(int i=0;i<n;i++)
    {
        cin>>item[i];
        j=max(item[i],j);      //maximum lunch can made
    }
    map<int,int> m;
    for(int i=0;i<n;i++)  //count no. of each item
    {
        m[item[i]]++;
    }
 int ans=0;
    while(i<=j)
    {
        int mid=i+(j-i)/2; //assumed lunch
        if(check(m,a,mid))
        {
            i=mid+1;
            ans=mid;
        }
        else
        j=mid-1;
        
    }
    cout<<ans<<endl;
    return 0;
}
