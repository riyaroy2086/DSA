//https://leetcode.com/problems/integer-break/

/**
Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.
Return the maximum product you can get.

 Example 1:

Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.


Example 2:

Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
*/

//---------------------------------------------------------------code here-----------------------------------------------------------------------------------//

class Solution {

    int func(int n,int dp[])
    {
        if(n<2) return 0; //since they can't be further divided

        if(dp[n]!=-1) return dp[n];

        for(int i=1;i<n;i++)  //since at i=n, the product will be 0
        {
           int currMax=Math.max(func(n-i,dp),n-i);

            dp[n]=Math.max(dp[n],currMax*i);

        }

        return dp[n];
    }

    public int integerBreak(int n) {

        int dp[]=new int[n+1];

        Arrays.fill(dp,-1);

        return func(n,dp);
        
    }
}
