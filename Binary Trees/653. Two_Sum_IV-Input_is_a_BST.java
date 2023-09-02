https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

/**
Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

Example 1:

Input: root = [5,3,6,2,4,null,7], k = 9
Output: true


Example 2:

Input: root = [5,3,6,2,4,null,7], k = 28
Output: false
*/

//---------------------------------------------------------------------code here-----------------------------------------------------------------------------//



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

    public void trav(TreeNode root,ArrayList<Integer> arr)
    {
        if(root==null) return;

        trav(root.left,arr);

        arr.add(root.val);

        trav(root.right,arr);
    }

    public boolean findTarget(TreeNode root, int k) {
        
        ArrayList<Integer> arr=new ArrayList<>();

        trav(root,arr);

        int start=0,end=arr.size()-1;

        while(start<end)
        {
         int s=arr.get(start)+arr.get(end);

         if(s==k) return true;

         else if(s>k) end--;

         else if(s<k) start++;   
        }

        return false;

    }
}
