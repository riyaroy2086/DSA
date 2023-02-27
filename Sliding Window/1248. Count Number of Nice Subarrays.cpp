class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int c=0,res =0,idx=0;
        for(int i=0;i<nums.size();i++)
        {         
            //if odd then reducing k = no. of continuous subarray units to be considered
            if(nums[i] % 2 !=0)
            {
                k--;
                c=0;
            }
            while(k==0) // now the no. od units fixed and time for arrangement selection
            {
                k+=nums[idx++] &1;
                c++;
            }
            res+=c;
        }
        return res;
    }
};
