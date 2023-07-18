// PROBLEM STATEMENT --------------------------->

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.

// SOLUTION ------------------------------------------------>

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0, m=0, h=nums.size()-1;
        int temp;
        while(m<=h)
        {
            switch(nums[m]){
                case 0 : 
                {
                   temp = nums[l];
                   nums[l] = nums[m];
                   nums[m] = temp;
                   l++;
                   m++;
                   break; 
                }
                case 1:
                {
                    //nums[m];
                    m++;
                    break;
                }
                case 2:
                {
                   temp = nums[h];
                   nums[h] = nums[m];
                   nums[m] = temp;
                   h--;
                   //m++;
                   break; 
                }
            }
            //return;
        } 
    }
};

// TIME AND SPACE C ------------------------------------------------->

Time complexity: The outer loop iterates over all the elements in the array nums, which takes a time of O(n). The inner loop iterates over the subarray that contains the elements that need to be swapped. The number of times the inner loop iterates is at most n, so the total time complexity of the code is O(n + n) = O(n).
Space complexity: The only additional space used is a few temporary variables. The size of the temporary variables is independent of the length of the array nums, so the space complexity of the code is O(1).

// SUBMISSION ------------------------------------------>

https://leetcode.com/problems/sort-colors/submissions/
