class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1) return 0;
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int> (m)); 
        dp[0][0] = 1;
        for(int i = 1;i<n;i++)
            if(dp[i-1][0] != 0 and obstacleGrid[i][0] != 1) dp[i][0] = 1;
        for(int i = 1;i<m;i++) 
            if(dp[0][i-1] != 0 and obstacleGrid[0][i] != 1) dp[0][i] = 1;
        for(int i = 1;i<n;i++){
            for(int j = 1;j<m;j++){
                if(obstacleGrid[i][j] != 1){
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
                }
            }
        }
        return dp[n-1][m-1];
    }
};
