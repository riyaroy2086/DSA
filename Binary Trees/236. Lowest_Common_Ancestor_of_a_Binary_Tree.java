/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        
        if(root==null || root==p|| root==q)
        {
            return root;  //keeping in mind that the general order of the tree is a pre-order traversal where the node comes first
        }

        TreeNode left=lowestCommonAncestor(root.left,p,q);  //storing the value that comes from the left sub-tree
        TreeNode right=lowestCommonAncestor(root.right,p,q); //storing the value that comes from the right sub-tree 
    
        if(left==null)
        {
            return right;
        }
        else if(right==null)
        {
            return left;
        }
        else
        {
            return root;
        }

    }
}
