// https://leetcode.com/problems/subarrays-with-k-different-integers/submissions/909694687/

//TC & SC -> O(N)

class Solution {
public:
    int atMostK(vector<int> &nums, int k)
    {
        int n = nums.size(),j=0,res =0;
        unordered_map<int,int> map;
        // map is used here to calculate the frequency of the unique ints
        for(int i=0;i<n;i++)
        {
            map[nums[i]]++;
            if(map[nums[i]] == 1) // visited
                k--;

            while(k<0) // unique ints are visited as per the value of k
            {
                map[nums[j]]--;
                if(!map[nums[j]])
                    k++;  
                j++;    
            } 
            res += i-j+1;      
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        int res = atMostK(nums,k)- atMostK(nums,k-1);
        return res; 
    }
};
