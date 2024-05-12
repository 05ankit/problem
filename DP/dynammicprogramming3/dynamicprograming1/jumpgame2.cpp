class Solution {
private:
    int minjumps(vector<int>& nums,int start,int end,vector<int> &memo)
    {
        if(start==end)
        {
            return 0;
        }
        if(memo[start]!=0)
        {
            return memo[start];
        }
        int ans=INT_MAX;
        for(int i=start+1;i<=end && i <=start+nums[start];i++)
        {
            int jumps=minjumps(nums,i,end,memo);
            if(jumps!=INT_MAX&&jumps+1<ans)
            {
                ans=jumps+1;
            }
        }
        return memo[start]=ans;
    }
public:
    int jump(vector<int>& nums) {
        vector<int> memo(nums.size());
        return minjumps(nums,0,nums.size()-1,memo);
    }
};
