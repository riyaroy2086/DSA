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

    HashMap<Integer,Integer> map=new HashMap<Integer,Integer>();

    public void trav(TreeNode root)
    {
        if(root==null)
        {
            return ;
        }
        trav(root.left);
        if(map.containsKey(root.val))
            {
                map.put(root.val,map.get(root.val)+1);
            }
            else
            {
                map.put(root.val,1);
            }
        trav(root.right);
    } 
    public int[] findMode(TreeNode root) {

        trav(root);
        int mode=0;
        
        for(Map.Entry<Integer, Integer> entry : map.entrySet())
        {
            if(entry.getValue()>mode)
            {
                mode=entry.getValue();
            }
        }
        
        ArrayList<Integer> arr=new ArrayList<Integer>();        

        for(Map.Entry<Integer, Integer> entry : map.entrySet())
        {
            if(entry.getValue()==mode)
            {
                //System.out.println(entry.getKey());
                arr.add(entry.getKey());
            }
        }
        int m[]=new int[arr.size()];
        for(int i=0;i<arr.size();i++)
        {
            m[i]=arr.get(i);
        }
        return m;
    }
}
