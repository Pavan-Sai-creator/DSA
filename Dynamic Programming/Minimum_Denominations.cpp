//https://www.codingninjas.com/codestudio/problems/minimum-elements_3843091?leftPanelTab=0
//https://www.youtube.com/watch?v=myPeWb3Y68A&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=21


// int f(int ind,int target,vector<int> &num,vector<vector<int>> &dp)
// {
//     if(ind==0)
//     {
//         if(target%num[ind]==0) return target/num[ind];
//         return 1e9;
//     }
//     if(dp[ind][target]!=-1) return dp[ind][target];
//     int notake = 0 + f(ind-1,target,num,dp);
//     int take = 1e9;
//     if(num[ind]<=target) take = 1 + f(ind,target-num[ind],num,dp);
    
//     return dp[ind][target]=min(take,notake);
// }

// TABULATION //

int minimumElements(vector<int> &num, int x)
{
    int n=num.size();
    vector<int> prev(x+1,0);
    vector<int> cur(x+1,0);
    for(int t=0;t<=x;t++)
    {
        if(t%num[0]==0) prev[t] = t/num[0];
        else prev[t] = 1e9;
    }
    
    for(int ind=1;ind<n;ind++)
    {
        for(int tar=0;tar<=x;tar++)
        {
            int notake = 0 + prev[tar];
            int take = 1e9;
            if(num[ind]<=tar) take = 1 + cur[tar-num[ind]];

            cur[tar]=min(take,notake);
        }
        prev=cur;
    }
    
    
    int ans = prev[x];
    if(ans>=1e9) return -1;
    else return ans;
}