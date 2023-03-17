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

    public TreeNode trav(TreeNode root,int l,int h)
    {
        if(root==null)
            return null;

        if(root.val<l)
            return trav(root.right,l,h);  //If the value is lower than low then return the right sub-tree
        
        if(root.val>h)
            return trav(root.left,l,h);   //If the value is higher than high then return the left sub-tree 

        root.left=trav(root.left,l,h);    //Else the values are in range and hence no need to change the 
        root.right=trav(root.right,l,h);  //the sub trees

        return root;
    }

    public TreeNode trimBST(TreeNode root, int low, int high) {

        TreeNode r=trav(root,low,high);

        return r;
        
    }
}
