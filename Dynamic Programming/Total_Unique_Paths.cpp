//https://www.codingninjas.com/codestudio/problems/total-unique-paths_1081470?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
//https://www.youtube.com/watch?v=AE39gJYuRog&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=8

int f(int i,int j,vector<vector<int>> &dp)
{
    if(i==0 && j==0) return 1;
    if(i<0 || j<0) return 0;
    
    if(dp[i][j]!=-1) return dp[i][j];
    int up = f(i-1,j,dp);
    int left = f(i,j-1,dp);
    
    return dp[i][j]=up+left;
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int> (n, -1));
	return f(m-1,n-1,dp);
}