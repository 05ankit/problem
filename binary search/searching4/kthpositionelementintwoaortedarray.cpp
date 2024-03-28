int countless(vector<int>& arr,int size, int key) {
    int left = 0;
    int right = size - 1;
    int count = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] < key) {
            count = mid + 1; 
            left = mid + 1;  
        }
        else {
            right = mid - 1;
        }
    }
    return count;
}

int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    // Write your code here
    int ans=0;
    int low=min(arr1[0],arr2[0]);
    int high=max(arr1[n-1],arr2[m-1]);
    while(low<=high)
    {
        int mid=(low+high)/2;
        int countlessthanmid=0;
        countlessthanmid=countless(arr1,n,mid);
        countlessthanmid+=countless(arr2,m,mid);
        if(countlessthanmid<k)
        {
            low=mid+1;
        }
        else if(countlessthanmid>k)
        {
            high=mid-1;
        }
        else
        {
            if(countlessthanmid==k)
            {
                ans=mid;
                low=mid+1;
            }
        }
    }
    return ans;
}
