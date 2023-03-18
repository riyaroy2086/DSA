class Solution {

    public int cat(int n,int dp[])
    {
        if(n==0 || n==1)
            return 1;
        
        if(dp[n]!=-1)
            return dp[n];

        int ans=0;

        for(int i=1;i<=n;i++)  //keeping every number till n (i) as root node to from unique bst
        {
            ans+=cat(i-1,dp)*cat(n-i,dp);
        }

        return dp[n]=ans;
    }


    public int numTrees(int n) {
        
        //This problem actually based on calculation of Catalan Number where,
        //C(n)=i=1 to i=n sumation of Ci*Cn-i

        int dp[]=new int[n+1];
        Arrays.fill(dp,-1);

        return cat(n,dp);

    }
}
