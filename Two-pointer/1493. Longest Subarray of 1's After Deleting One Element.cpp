Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

 

Example 1:

Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
Example 2:

Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
Example 3:

Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.

// SOLUTION-------->>
  
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = INT_MIN;
        int z=0 , l=0;
        int n = nums.size();
        for(int r=0;r<n;++r)
        {
            if(nums[r]==0) ++z;
            if(z>1 && nums[l] == 0) --z;

            res=max(res,r-l);
        }
        return res > INT_MIN ? res : 0;
    }
};

// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/submissions/1010221340/
