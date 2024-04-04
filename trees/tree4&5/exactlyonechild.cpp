#include<bits/stdc++.h>
using namespace std;
bool OneChild(vector<int> &preorder)
{
    int l0w_bound=INT_MIN,up_bound=INT_MAX;
    int size=preorder.size();
    for(int i=1;i<size;i++)
    {
         if(preorder[i]<=low_bound||preorder[i]>=up_bound)
         {
             return false;
         }
         if(preorder[i]>preorder[i-1])
         {
             low_bound=preorder[i-1];
         }
         else
         {
             up_bound=preorder[i-1];
         }
    }
    return true;
}
int main()
{
    int size;
    cin>>size;
    vector<int> preorder(size);
    for(int i=0;i<size;i++)
    {
        cin>>preorder[i];
    }
    bool ans=OneChild(preorder);
    cout<<ans;

    return 0;
}
