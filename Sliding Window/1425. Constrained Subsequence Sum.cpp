Given an integer array nums and an integer k, return the maximum sum of a non-empty subsequence of that array such that for every two consecutive integers in the subsequence, nums[i] and nums[j], where i < j, the condition j - i <= k is satisfied.

A subsequence of an array is obtained by deleting some number of elements (can be zero) from the array, leaving the remaining elements in their original order.

 

Example 1:

Input: nums = [10,2,-10,5,20], k = 2
Output: 37
Explanation: The subsequence is [10, 2, 5, 20].
Example 2:

Input: nums = [-1,-2,-3], k = 1
Output: -1
Explanation: The subsequence must be non-empty, so we choose the largest number.
Example 3:

Input: nums = [10,-2,-10,-5,20], k = 2
Output: 23
Explanation: The subsequence is [10, -2, -5, 20].
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104

// SOLUTION ---->>  

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        deque<int> dq; // with the window k
        // dq stores dp[i - k], dp[i - k + 1], ..., dp[i - 1] whose values are > 0
        // in decreasing order.

        for(int i=0;i<n;++i)
        {
            if(dq.empty()) 
                dp[i] = nums[i];
            else 
                dp[i] = nums[i] + max(dq.front(),0);
                //The max function with 0 is used to ensure that we don't include any negative value from the deque.
            while(!dq.empty() && dq.back() < dp[i])
                dq.pop_back();
            dq.push_back(dp[i]);
            //We then perform a while loop to remove all elements from the back of the deque (dq) that are less than the current dp[i]. This helps in maintaining a decreasing order of values in the deque.

            if(i>=k && dp[i-k] == dq.front())
                dq.pop_front();  
            // we check if the current index i is at least k positions away from the start (to form a valid window of size k). If this condition is met and the front element of the deque (dq.front()) is equal to the dp[i - k], it means this element will no longer be in the current sliding window, so we remove it from the front of the deque.          
        }
        return *max_element(dp.begin(),dp.end());
    }
};

//https://leetcode.com/problems/constrained-subsequence-sum/submissions/1010335637/
