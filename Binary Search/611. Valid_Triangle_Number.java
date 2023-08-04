//https://leetcode.com/problems/valid-triangle-number/

class Solution {

    public int triangleNumber(int[] nums) {

        int count=0;

        int n=nums.length;

        Arrays.sort(nums);

        for(int i=n-1;i>=2;i--)    //here the range of the loop is required to form triplets
        {
            int l=0,h=i-1;

            while(l<h)
            {
                if(nums[h]+nums[l]>nums[i]) 
                {
                    count+=(h-l);  //since all the elements in the range shall satisfy the necessary condition
                    h--;
                }
                else
                {
                    l++;
                }
            }
        }

        return count;

    }
}
