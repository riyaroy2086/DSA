//https://leetcode.com/problems/partition-list/

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

    int findMax(int[] nums,int si,int ei)
    {
        int max=Integer.MIN_VALUE;
        int idx=si;

        for(int i=si;i<=ei;i++)
        {
            if(nums[i]>max)
            {
                max=nums[i];
                idx=i;
            }
        }

        return idx;
    }

     TreeNode construct(int nums[],int si,int ei)
    {
        if(si>ei) return null;

        if(si==ei) return new TreeNode(nums[si]);

        int idx=findMax(nums,si,ei);  //finding the maximum element between si and ei at each recursive step

        TreeNode root=new TreeNode(nums[idx]);  //making the max element at each step the root node

        root.left=construct(nums,si,idx-1);     //taking the left part of the array storing it in the left sub-tree and making the recursive call

        root.right=construct(nums,idx+1,ei);    //recursive call for the right part of the array

        return root;
    }

    public TreeNode constructMaximumBinaryTree(int[] nums) {

        TreeNode root=construct(nums,0,nums.length-1);;
        
        return root;
        
    }
}
