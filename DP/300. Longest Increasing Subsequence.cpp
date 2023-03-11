// https://leetcode.com/problems/longest-increasing-subsequence/submissions/913430339/

class Solution {
    //TC -> O(N^2) & Sc -> O(N)
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;

        int n = nums.size();
        vector<int> dp(n,1);
        
        for(int i = 1;i<n;i++)
            for(int j=0;j<i;j++)
                if(nums[j]<nums[i])
                    dp[i] = max(dp[i],dp[j]+1);

        return *max_element(begin(dp),end(dp));
    }
};
