#include<bits/stdc++.h>
using namespace std;
int main()
{
  vector<int> arr;
  vector<int> queri;
  int count=0;
  int height;
  int queries;
  int N;
  cin>>N;
  int Q;
  cin>>Q;
  for(int i=0;i<N;i++)
  {
    cin>>height;
    arr.push_back(height);
  }
  for(int i=0;i<Q;i++)
  {
    cin>>queries;
    queri.push_back(queries);
  }
  int low=0;
  int high=N;
  sort(arr.begin(),arr.end());
  for(int i=0;i<queri.size();i++)
  {
      low=0,high=N;
    while(low<=high)
  {
    int mid=(low+high)/2;
    if(arr[mid]>=queri[i])
    {
      count=N-mid;
      high=mid-1;
     
    }
    else
    {
      low=mid+1;
      
    }
  }
  cout<<count<<endl;
  count=0;
  }
  return 0;
}