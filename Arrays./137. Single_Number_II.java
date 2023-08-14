//https://leetcode.com/problems/single-number-ii/

/*
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99
*/

class Solution {
    public int singleNumber(int[] nums) {

        Arrays.sort(nums);
        int a=0;
        boolean f=false;

        for(int i=0;i<nums.length-2;i++)
        {
            if(i==0 && nums[i]!=nums[i+1] && nums[i]!=nums[i+2]) return nums[0];

            if(nums[i]!=nums[i+1] && nums[i+1]!=nums[i+2])
            {
                f=!f;
                a=i+1;
                break;
            }
        }

        if(f) return nums[a];
        
        return nums[nums.length-1];
        
    }
}
