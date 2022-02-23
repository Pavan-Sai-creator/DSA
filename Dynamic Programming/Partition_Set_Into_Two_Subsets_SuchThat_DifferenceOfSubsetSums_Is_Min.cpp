//https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
//https://www.youtube.com/watch?v=GS_OqZb2CWc&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=17

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totSum=0;
	for(int i=0;i<n;i++)
    {
        totSum+=arr[i];
    }
    int k = totSum;
    vector<vector<bool>> dp(n,vector<bool>(k+1,0));
    for(int ind=0;ind<n;ind++)
        dp[ind][0] = true;
    if(arr[0]<=k) dp[0][arr[0]]=true;
    for(int ind=1;ind<n;ind++)
    {
        for(int target=1;target<=k;target++)
        {
            bool notake = dp[ind-1][target];
            bool take=false;
            if(arr[ind]<=target) take = dp[ind-1][target-arr[ind]];
    
            dp[ind][target]=take|notake;
        }
    }
    int mini = 1e9;
    for(int s1=0;s1<=totSum/2;s1++)
    {
        if(dp[n-1][s1]==true)
        mini = min(mini,abs((totSum-s1)-s1));
    }
    return mini;
}
