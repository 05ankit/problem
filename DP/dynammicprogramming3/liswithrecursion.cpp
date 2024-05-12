class Solution {
private:
    int lis(vector<int>& nums,int idx,int prev)
    {
        if(idx==nums.size())
        {
            return 0;
        }
        int take=0;
        if(nums[idx]>prev)
        {
            take=1+lis(nums,idx+1,nums[idx]);
        }
        int nontake=lis(nums,idx+1,prev);
        // cout<<1;
        return max(take,nontake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        return lis(nums,0,INT_MIN);
    }
};
