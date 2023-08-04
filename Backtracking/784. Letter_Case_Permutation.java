//https://leetcode.com/problems/letter-case-permutation/

class Solution {

    void permute(String s,int n,int i,List<String> arr,String w)
    {
        if(i==n)
        {
            arr.add(w);
            return;
        }

       
            char c=s.charAt(i);

            if(Character.isAlphabetic(c))
            {
                if(Character.isLowerCase(c))
                    permute(s,n,i+1,arr,w+Character.toUpperCase(c));
                
                else
                    permute(s,n,i+1,arr,w+Character.toLowerCase(c));
            }

            permute(s,n,i+1,arr,w+c);

    }

    public List<String> letterCasePermutation(String s) {

        List<String> arr=new ArrayList<>();
         
         permute(s,s.length(),0,arr,"");

         return arr;
        
    }
}
