class Solution {

    public int paths(int i,int j,int dp[][])
    {
        if(i<0 || j<0) return 0;

        if(i==0 && j==0) return 1;

        if(dp[i][j]!=-1) return dp[i][j];
        
        int left=paths(i,j-1,dp);
        int up=paths(i-1,j,dp);

        return dp[i][j]=left+up;
    }

    public int uniquePaths(int m, int n) {

        //using top down approach (Memoization)

        int dp[][]=new int[m][n];

        for (int[] row: dp)
            Arrays.fill(row, -1);

        return paths(m-1,n-1,dp);
        
    }
}
