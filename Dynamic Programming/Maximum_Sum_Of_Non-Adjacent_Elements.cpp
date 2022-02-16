//https://leetcode.com/problems/house-robber/
//https://www.youtube.com/watch?v=GrMBfJNk_NY&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=6
class Solution {
    int fun(int ind, vector<int> &nums,vector<int> &dp)
    {
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        int pick = nums[ind] + fun(ind-2,nums,dp);
        int notpick = 0 + fun(ind-1,nums,dp);
        
        return dp[ind]= max(pick,notpick);
    }
public:
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> dp(n,-1);
        return fun(n-1,nums,dp);
    }
};