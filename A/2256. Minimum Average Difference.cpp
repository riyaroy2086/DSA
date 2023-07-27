You are given a 0-indexed integer array nums of length n.

The average difference of the index i is the absolute difference between the average of the first i + 1 elements of nums and the average of the last n - i - 1 elements. Both averages should be rounded down to the nearest integer.

Return the index with the minimum average difference. If there are multiple such indices, return the smallest one.

Note:

The absolute difference of two numbers is the absolute value of their difference.
The average of n elements is the sum of the n elements divided (integer division) by n.
The average of 0 elements is considered to be 0.
 

Example 1:

Input: nums = [2,5,3,9,5,3]
Output: 3
Explanation:
- The average difference of index 0 is: |2 / 1 - (5 + 3 + 9 + 5 + 3) / 5| = |2 / 1 - 25 / 5| = |2 - 5| = 3.
- The average difference of index 1 is: |(2 + 5) / 2 - (3 + 9 + 5 + 3) / 4| = |7 / 2 - 20 / 4| = |3 - 5| = 2.
- The average difference of index 2 is: |(2 + 5 + 3) / 3 - (9 + 5 + 3) / 3| = |10 / 3 - 17 / 3| = |3 - 5| = 2.
- The average difference of index 3 is: |(2 + 5 + 3 + 9) / 4 - (5 + 3) / 2| = |19 / 4 - 8 / 2| = |4 - 4| = 0.
- The average difference of index 4 is: |(2 + 5 + 3 + 9 + 5) / 5 - 3 / 1| = |24 / 5 - 3 / 1| = |4 - 3| = 1.
- The average difference of index 5 is: |(2 + 5 + 3 + 9 + 5 + 3) / 6 - 0| = |27 / 6 - 0| = |4 - 0| = 4.
The average difference of index 3 is the minimum average difference so return 3.
Example 2:

Input: nums = [0]
Output: 0
Explanation:
The only index is 0 so return 0.
The average difference of index 0 is: |0 / 1 - 0| = |0 - 0| = 0.
 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105

// ------------------------//

// TC-> O(N)
// SC-> O(1)

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        // int low = 0, high = nums.sie()-1;
        // int mid = (high - low)/2 ;

        // --------------------------------------------------//

        // SUFFIX AND PREFIX SUM

        int n = nums.size();
        long long rt_sum =0 , lt_sum = 0;
        int idx = 0;
        int min_val = INT_MAX;

        for(int i:nums)
            rt_sum += i;

        // vector<bool> dp(sum+1,false);    
        // dp[0] = true;

        for(int i=0;i<n;++i)
        {
            lt_sum += nums[i];
            rt_sum -= nums[i];
            // AVERAGES
            long long fst = (lt_sum/(i+1));
            long long lst = i<n-1 ? (rt_sum/(n-i-1)) : 0;
            int diff = abs(lst-fst);

            // diff = min(min_val,diff);
            if(diff<min_val) 
            {
                min_val = diff;
                idx = i;
            }
        }
                // for(int k= sum;k>=nums[i];--k)
                //     dp[k] = dp[k] || dp[k-nums[i]];
                    
        

        // for(int h=sum/2;h<=sum;++h)
        //     if(dp[h])
        //         res = min(res,sum-2*h);

        return idx;                     
    }
};

// https://leetcode.com/problems/minimum-average-difference/submissions/1005701737/
