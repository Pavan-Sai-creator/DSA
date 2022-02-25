//https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
//https://www.youtube.com/watch?v=HgyouUi11zk&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=23


#include<bits/stdc++.h>
long countWaysToMakeChange(int *coins, int n, int value)
{
    vector<vector<long long>> dp(n + 1, vector<long long> (value + 1, 0));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= value; j++) {
            if (coins[i - 1] <= j) {
                dp[i][j] = dp[i][j - coins[i-1]] + dp[i-1][j];
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][value];
}