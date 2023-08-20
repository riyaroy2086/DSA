//https://leetcode.com/problems/palindromic-substrings/

/**
Given a string s, return the number of palindromic substrings in it.

Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
*/

//--------------------------------------------------------------------code here------------------------------------------------------------------------------//

class Solution {
    public int countSubstrings(String s) {

        boolean dp[][]=new boolean[s.length()][s.length()];

        int count=0;

        //Here we will use the concept of the matrix
        //Here g represents the gap as well as the diagonal in which we currently are in
        //i -> rows which will always start from 0
        //j -> columns which will change according to diagonal/'g'
        //Refer to the notes for further reference

        for(int g=0;g<dp.length;g++)
        {
            for(int i=0,j=g;j<dp[0].length;i++,j++)
            {
                if(g==0)  dp[i][j]=true;

                else if(g==1)
                {
                    if(s.charAt(i)==s.charAt(j)) dp[i][j]=true;

                    else dp[i][j]=false;
                }
                else
                {
                    if(s.charAt(i)==s.charAt(j) && dp[i+1][j-1]==true) dp[i][j]=true;

                    else dp[i][j]=false; 

                }

                if(dp[i][j]) count++;
            }
            
        }

        return count;
        
    }
} 
