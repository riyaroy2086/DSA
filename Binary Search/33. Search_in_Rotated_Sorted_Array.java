//https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
    public int search(int[] nums, int target) {

        int l=0,r=nums.length-1;

        while(l<=r) //giving '=' as to avoid the cases for singular array
        {
            int mid=(l+r)/2;

            if(target==nums[mid]) return mid;

            if(nums[l]<=nums[mid])
            {
                if(target<nums[l] || target>nums[mid])
                    l=mid+1;
                else
                    r=mid-1;;
            }
            else
            {
                if(target>nums[r] || target<nums[mid])
                    r=mid-1;
                else
                    l=mid+1;
            }
            
        }  
        return -1;
        
    }
}
