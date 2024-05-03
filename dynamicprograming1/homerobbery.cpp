class Solution {
private: 
    int robery(vector<int>& nums,int i,vector<int>& ans)
    {
        if(i>nums.size()-1)
        {
            return 0;
        }
        if(ans[i]!=-1)
        {
            return ans[i];
        }
        int take=nums[i]+robery(nums,i+2,ans);
        int nontake=robery(nums,i+1,ans);
        return ans[i]=max(take,nontake);
    }    
public:
    int rob(vector<int>& nums) {
       vector<int> ans(nums.size(),-1);
       return robery(nums,0,ans);
    }
};
