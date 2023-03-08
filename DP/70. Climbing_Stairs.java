class Solution {

    public int climb(int n,int dp[])
    {
        if(n==0 || n==1) return 1;

        if(dp[n]!=-1) return dp[n];

        
        return dp[n]=climb(n-1,dp)+climb(n-2,dp);
            

    }

    public int climbStairs(int n) {
      
            //Solving it using memoization

            int dp[]=new int[n+1];

            Arrays.fill(dp,-1);

            return climb(n,dp);
    }
}
