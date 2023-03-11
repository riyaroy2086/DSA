
//https://leetcode.com/problems/longest-palindrome/

class Solution {
    public int longestPalindrome(String s) {

        if(s.length()==1) return 1;

        char c[]=s.toCharArray();
        HashMap<Character,Integer> map=new HashMap<>();

        for(char i:c)
        {
            map.put(i,map.getOrDefault(i,0)+1);
        }

        int even=0,odd=0;
        boolean flag=false;
        
        for(Map.Entry<Character,Integer> x:map.entrySet())
        {
            if(x.getValue()%2==0)
            {
                even+=x.getValue();
            } 

            else
            {
                odd+=x.getValue()-1;
                flag=true;
            } 

        }
        
        return (odd+even)+(flag?1:0);
        
    }
}
