//https://leetcode.com/problems/binary-tree-paths/

/**
Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

Example 1:

Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
*/

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

    void dfs(List<String> arr,TreeNode root,String s)
    {
        if(root==null) return;

        s=s+root.val+"->";

        if(root.left==null && root.right==null)  //checking if its the last node
        {
            arr.add(s.substring(0,s.length()-2));  //adding the formed string into the list excluding the extra "->" in the end
            return;
        } 

        dfs(arr,root.left,s);  
                                    // Backtracking
        dfs(arr,root.right,s);   

    }

    public List<String> binaryTreePaths(TreeNode root) {

        List<String> arr=new ArrayList<>();

        dfs(arr,root,"");

        return arr;
        
    }
}
