//https://leetcode.com/problems/maximum-subarray/

/**
Given an integer array nums, find the subarray with the largest sum, and return its sum.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.


Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.


Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
*/

//-------------------------------------------------------------------------code here------------------------------------------------------------------------------//

class Solution {
    public int maxSubArray(int[] nums) {

        //Using Kadane's algorithm

        int currBestSum=nums[0];

        int overallBestSum=nums[0];

        for(int i=1;i<nums.length;i++)
        {

            if(currBestSum<0) currBestSum=nums[i];  //if the sum from the previous sub-array is negetaive then no point in adding the number...new subarray formed

            else currBestSum+=nums[i];

            overallBestSum=Math.max(currBestSum,overallBestSum);
        }

        return overallBestSum;
        
    }
}
