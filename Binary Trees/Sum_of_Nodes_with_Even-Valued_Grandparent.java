//https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

/**
Given the root of a binary tree, return the sum of values of nodes with an even-valued grandparent. If there are no nodes with an even-valued grandparent, return 0.

A grandparent of a node is the parent of its parent if it exists.
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

    int s=0;

    void dfs(TreeNode root)
    {
        if(root==null) return;

        if(root.val%2==0)
        {
            if(root.left!=null) //if there is a left-child
            {

                if(root.left.left!=null) s+=root.left.left.val; //adding up the left grand-child (1st)

                if(root.left.right!=null) s+=root.left.right.val;//adding up the right grand-child(2nd)

            }
            if(root.right!=null)  //if there is a right-child
            {

                if(root.right.left!=null) s+=root.right.left.val; //adding the 3rd grand-child

                if(root.right.right!=null) s+=root.right.right.val; //adding the 4th grand-child

            }
        }

        dfs(root.left);
        dfs(root.right);
    }

    public int sumEvenGrandparent(TreeNode root) {

        //Brute force method

        /*
        since we know that a node in a binary tree has atmost 4 children, so we will  add up those children of the nodes(if not null) when the value of the node is even.
        */

        dfs(root);

        return s;
        
    }
}
