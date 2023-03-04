// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/submissions/909023275/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        //Tc-> O(logN)

        int l = 0;
        int r = nums.size()-1;

        while(l<=r)
        {
            int m = l+(r-l)/2;
            // if mid is the target
            if(nums[m]== target)
                return true;
            // in case of duplicates 
            // e.g. 1)  0 0     
            if(nums[m] == nums[l] && nums[m] ==nums[r])
            {
                l++;
                r--;
            }
            // l to m sorting
            else if(nums[l]<=nums[m])
            {
                if(nums[l]<= target && target < nums[m]) // l to m
                    r = m-1;   // so reducing r to mid-1
                else
                    l = m+1;   // else target present in the 2nd half
            }
            // m to n-1 sorting 
            else if(nums[l]>nums[m])
            {
                if(target > nums[m] && target <= nums[r]) //m to size-1
                    l = m+1; // target lies in the 2nd half    
                else      
                    r = m-1; // target lies in the 1st half  
            }     
        }
        return false;
    }
};
