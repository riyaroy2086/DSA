class Solution {

    public int heist(int nums[],int n)
    {

        int dp[]=new int[n];
    
        dp[0]=nums[0];

        for(int i=1;i<n;i++)
        {
            int pick=nums[i];  //since everytime the element itself will be constant

            if(i>1)
                pick+=dp[i-2];
            
            int notpick=dp[i-1];

            dp[i]=Math.max(pick,notpick);
        }

        return dp[n-1];

    }

    public int rob(int[] nums) {

        //Used the tabulation approach for this problem
        return heist(nums,nums.length);
        
    }
}
