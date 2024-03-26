class Solution {
public:
    bool issolutionpossible(int mid, vector<int>& nums, int maxOperations)
    {
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>mid)
            {
                if(nums[i]%mid==0)
                {
                    count+=nums[i]/mid -1;
                }
                else
                {
                    count+=nums[i]/mid;
                }
            }
        }
        if(count<=maxOperations)
        {
            return true;
        }
        else
        {
            return false;
        }
    }    
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1;
        int maxx=0;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            maxx=max(maxx,nums[i]);
        }
        int high=maxx;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(issolutionpossible(mid,nums,maxOperations))
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
};
