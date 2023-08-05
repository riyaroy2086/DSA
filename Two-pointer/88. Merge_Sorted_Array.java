//https://leetcode.com/problems/merge-sorted-array/

class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {


        // Optimised method with two-pointer concept

        int i=m-1;  // pointer to track the nums1 ending index 

        int j=n-1;  // pointer to track the nums2 ending index 

        int k=(m+n)-1; // pointer to track the sorted nums1 ending index 

        while(i>=0 && j>=0)
        {
            if(nums1[i]>nums2[j])   nums1[k--]=nums1[i--];

            else    nums1[k--]=nums2[j--];
                
        }

        while(j>=0) nums1[k--]=nums2[j--];  // to insert the nums2 elements if its unfinished



        //**********************************************************************************************//

        //Brute-force method

        /*
        int p=0;

        for(int i=m;i<m+n;i++)
        {
            nums1[i]=nums2[i-m];
        }

        Arrays.sort(nums1);
        
        */
    }
}
