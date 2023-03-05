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
    ArrayList<Integer> arr=new ArrayList<>();

    public void trav(TreeNode root)
    {
        if(root==null)
            return;
        trav(root.left);
        arr.add(root.val);
        trav(root.right);
    }

    public int minDiffInBST(TreeNode root) {

        trav(root);

        ArrayList<Integer> diff=new ArrayList<Integer>();

        for(int i=0;i<arr.size()-1;i++)
        {
            diff.add(arr.get(i+1)-arr.get(i));
        }

        return Collections.min(diff);
        
    }
}
