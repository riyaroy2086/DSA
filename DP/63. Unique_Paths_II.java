class Solution {

    public int paths(int i,int j,int dp[][],int obstacleGrid[][])
    {
        if(i<0 || j<0 || obstacleGrid[i][j]==1) return 0;

        if(i==0 && j==0) return 1;

        if(dp[i][j]!=-1) return dp[i][j];
        
        int left=paths(i,j-1,dp,obstacleGrid);
        int up=paths(i-1,j,dp,obstacleGrid);

        return dp[i][j]=left+up;
    }

    public int uniquePathsWithObstacles(int[][] obstacleGrid) {

        int m=obstacleGrid.length;
        int n=obstacleGrid[0].length;
        
        int dp[][]=new int[m][n];

        for (int[] row: dp)
            Arrays.fill(row, -1);

        return paths(m-1,n-1,dp,obstacleGrid);
        
    }
}
