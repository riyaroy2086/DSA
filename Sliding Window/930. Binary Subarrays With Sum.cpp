class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // using hashmap
        // TC -> O(N) and SC-> O(N)

        unordered_map <int,int> m{{0,1}};
        int presum=0,res=0;
        for(int i : nums)
        {
            presum+=i;
            res+=m[presum-goal];
            m[presum]++;

        }
        return res;

        // using sliding window easy
        // TC -> O(N) and SC-> O(1)

        if(goal <0) return 0;
        int i,j=0;
        int sum=0;
        for(i=0;i<nums.size();i++)
        {
            goal-=nums[i];
            while(goal<0)
            {
                goal+=nums[j++]; // decreasing the front window
            }
            sum=i-j+1;
        }
        //c++;
        return sum;
    }
};
