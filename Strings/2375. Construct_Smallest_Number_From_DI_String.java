//https://leetcode.com/problems/construct-smallest-number-from-di-string/

class Solution {
    public String smallestNumber(String pattern) {

        Stack<Integer> nums=new Stack<>();

        String s="";

        for(int i=0;i<=pattern.length();i++)   //since the length of the pattern string is smaller than the resulting string
        {
            nums.push(i+1);

            if(i==pattern.length() || pattern.charAt(i)=='I' )  //the order of shall be maintained to avoid index out of bound issue in the last index of the string pattern
            {
                while(!nums.isEmpty())
                {
                    s=s+nums.pop().toString();
                }
            }
        }

        return s;
        
    }
}
