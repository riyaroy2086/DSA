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
        arr.add(root.val);
        trav(root.left);
        trav(root.right);
    }


    public int rangeSumBST(TreeNode root, int low, int high) {

        trav(root);
        int s=0;

        for(int i:arr)
        {
            if(i>=low && i<=high)
                s+=i;
        }

        return s;
        
    }
}
