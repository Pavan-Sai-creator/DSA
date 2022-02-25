//https://www.codingninjas.com/codestudio/problems/target-sum_4127362?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=1
//https://www.youtube.com/watch?v=b3GD8263-PQ&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=22

int mod = (int)(1e9+7);
int f(int ind,int sum,vector<int> &num,vector<vector<int>> &dp)
{
    if(ind==0)
    {
        if(sum==0 && num[0]==0) return 2;
        if(num[0]==sum || sum==0) return 1;
        return 0;
    }
    if(dp[ind][sum]!=-1) return dp[ind][sum];
    int notake = f(ind-1,sum,num,dp);
    int take = 0;
    if(num[ind]<=sum) take = f(ind-1,sum-num[ind],num,dp);
    
    return dp[ind][sum] = (notake+take);
}

int findWays(vector<int> &num,int target)
{
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    return f(n-1,target,num,dp);
}

int countPartitions(int n, int d, vector<int> &arr) {
    int totSum=0;
    for(int i=0;i<n;i++)
        totSum+=arr[i];
    if(totSum-d<0 || (totSum-d)%2) return false;
    return findWays(arr,(totSum-d)/2);
}

int targetSum(int n, int target, vector<int>& arr) {
    return countPartitions(n,target,arr);
}
