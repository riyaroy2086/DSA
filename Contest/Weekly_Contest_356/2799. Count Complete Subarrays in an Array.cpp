You are given an array nums consisting of positive integers.

We call a subarray of an array complete if the following condition is satisfied:

The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
Return the number of complete subarrays.

A subarray is a contiguous non-empty part of an array.

 

Example 1:

Input: nums = [1,3,1,2,2]
Output: 4
Explanation: The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2], [3,1,2] and [3,1,2,2].
Example 2:

Input: nums = [5,5,5,5]
Output: 10
Explanation: The array consists only of the integer 5, so any subarray is complete. The number of subarrays that we can choose is 10.
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 2000

// SOLUTION -------------------------------------------------->>

  class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        int s = unordered_set<int>(nums.begin(),nums.end()).size();
        unordered_map<int,int> m;
        int i=0,res =0;
        for(int num=0;num<n;++num)
        {
            ++m[nums[num]];
            if(m[nums[num]]==1) s--;
            while(s==0)
            {
                m[nums[i]]--;
                if(m[nums[i++]]==0) s++;
            }
            res+= i;
        } 
        return res;    
        
        // int sum=0,c=0,n=nums.size();
        // for(int i=0;i<n;++i)
        // {
        //     sum+=nums[i];
        //     if(sum == i+1) c++;
        // }
        // return c;   
        //   int count = 0;
        //   int sum = 0;
        //   for (int i = 0; i < nums.size(); i++) {
        //     if (sum <= 0) {
        //       sum = nums[i];
        //     } else {
        //       sum += nums[i];
        //     }

        //     if (sum == i + 1) {
        //       count++;
        //     }
        //   }
        //   return count;
    }
};
