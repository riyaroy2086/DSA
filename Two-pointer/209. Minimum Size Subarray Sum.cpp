Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray
 whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
 

Constraints:

1 <= target <= 109
1 <= nums.length <= 105
1 <= nums[i] <= 104
 

Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).

// SOLUTION -------------------------------------->>

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int sum = 0;
       int n = nums.size();
       int ans = INT_MAX;

       for(int l=0,r=0;r<n;++r)
       {
           sum+= nums[r]; // sum of the array elements
           while(sum>=target) // sum of subaarays atleast k 
           {
               ans = min(ans,r-l+1); //length of the current subarray (i.e., r - l + 1)
               sum -= nums[l++]; // removes the first element of the subarray from sum by incrementing l and subtracting the first element of nums from sum--->>> prefix sum concept
           }
       }
       return ans < INT_MAX ? ans : 0;

    }
};

// https://leetcode.com/problems/minimum-size-subarray-sum/submissions/1009642413/
