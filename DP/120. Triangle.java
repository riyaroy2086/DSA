class Solution {

    public int mps(List<List<Integer>> arr,int i,int j,int dp[][])
    {
        if(i==arr.size()-1)
            return arr.get(i).get(j);

        if(dp[i][j]!=-1)
            return dp[i][j];

        int left=arr.get(i).get(j)+ mps(arr,i+1,j,dp);
        int right=arr.get(i).get(j)+ mps(arr,i+1,j+1,dp);

        return dp[i][j]=Math.min(left,right);
    }

    public int minimumTotal(List<List<Integer>> triangle) {

        //using top-down approach(DFS)

        int n=triangle.size();
        int dp[][]=new int[n][n];

        for (int[] row: dp)
            Arrays.fill(row, -1);

        return mps(triangle,0,0,dp);
        
    }
}
