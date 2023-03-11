//https://leetcode.com/problems/largest-divisible-subset/submissions/913444379/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //TC -> O(N^2)
        //SC -> O(N^2)
        //Top - down approach

        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> prev(n,-1);

        if(n==0) return nums; // or return {};

        int max_idx =0;

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j] ==0 && dp[i]<dp[j]+1)  
                    {
                        dp[i] =dp[j]+1;
                        prev[i] =j;
                    }
            }
            if(dp[i]>dp[max_idx])   
                max_idx=i;
        }

        vector<int> ans ;
        int k =max_idx;
        while(k>=0)
        {
            ans.push_back(nums[k]);
            k = prev[k];
        }
        return ans;
    }
};
