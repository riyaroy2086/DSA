//https://leetcode.com/problems/find-unique-binary-string/

class Solution {

    String ans="";
    void  dfs(String[] nums,String s)
    {
        if(s.length()==nums.length)
        {
            if(!Arrays.asList(nums).contains(s))
            {
                ans=s;
            }
            return;
        }

         dfs(nums,s+"0");
         dfs(nums,s+"1");
    }

    public String findDifferentBinaryString(String[] nums) {

       
       dfs(nums,"");

        return ans;
    }
}
