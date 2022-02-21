//https://www.codingninjas.com/codestudio/problems/maximum-path-sum-in-the-matrix_797998?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
//https://www.youtube.com/watch?v=N_aJ5qQbYA0&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=13

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m = matrix[0].size();
    int dp[n][m];
  
        for(int j=0;j<m;j++)
        {
            dp[0][j]=matrix[0][j];
        }
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int up = matrix[i][j] + dp[i-1][j];
            int upleft = matrix[i][j];
            if(j-1>=0) upleft+= dp[i-1][j-1];
            else upleft+= -1e8;
            int upright = matrix[i][j];
            if(j+1<m) upright += dp[i-1][j+1];
            else upright += -1e8;
            dp[i][j] = max(up,max(upleft,upright));
        }
    }
    int maxi = -1e8;
    for(int j=0;j<m;j++)
    {
        maxi = max(maxi,dp[n-1][j]);
    }
    return maxi;
}