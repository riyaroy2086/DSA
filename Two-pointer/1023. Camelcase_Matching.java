//https://leetcode.com/problems/camelcase-matching/

class Solution {

    boolean func(String s,String pattern)
    {
        int c=0;           //to iterate over the entire string pattern

        int extraCap=0;   //to check if extra cap letters are present in the string 

        for(int i=0;i<s.length();i++)
        {
            
            if(c<pattern.length() && s.charAt(i)==pattern.charAt(c)) c++;  

            else if(s.charAt(i)>='A' && s.charAt(i)<='Z') extraCap++;   /*'elseif' used instead of just 'if' to avoid miscalculation of cap letters due to 
                                                                            checking of simultaneous condition */
                
        }

        return(c==pattern.length() && extraCap==0);
    }

    public List<Boolean> camelMatch(String[] queries, String pattern) {

        List<Boolean> arr=new ArrayList<>();

        for(int i=0;i<queries.length;i++)
        {
            arr.add(func(queries[i],pattern));
        }
        
        return arr;
    }
}
