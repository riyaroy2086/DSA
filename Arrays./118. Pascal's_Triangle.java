class Solution {

    public List<List<Integer>> generate(int numRows) {

        List<Integer> curr=new ArrayList<Integer>();
        List<Integer> prev=new ArrayList<Integer>();
        List<List<Integer>> ans=new ArrayList<>();

        for(int i=0;i<numRows;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j==0 || j==i)
                {
                    curr.add(1);
                }
                else
                {
                    curr.add(prev.get(j-1)+prev.get(j));
                }
            }
            prev=curr;
            ans.add(curr);
            curr=new ArrayList();
        }
        
        return ans;
      }
}   
