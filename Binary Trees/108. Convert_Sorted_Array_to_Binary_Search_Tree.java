//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

/**
Given an integer array nums where the elements are sorted in ascending order, convert it to a 
height-balanced binary search tree.

Example 1:

Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:

Example 2:

Input: nums = [1,3]
Output: [3,1]
Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
*/

//---------------------------------------------------------------------code here---------------------------------------------------------------------------//

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

    TreeNode trav(int[] nums,int l,int r)
    {
        if(l>r) return null;

        int mid=l+(r-l)/2;

        TreeNode root=new TreeNode(nums[mid]);

        root.left=trav(nums,l,mid-1);

        root.right=trav(nums,mid+1,r);

        return root;
        
    }

    public TreeNode sortedArrayToBST(int[] nums) {

        return trav(nums,0,nums.length-1);
        
    }
}
