//https://leetcode.com/problems/longest-palindromic-substring/

/**
Given a string s, return the longest 
palindromic
 
Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.


Example 2:

Input: s = "cbbd"
Output: "bb"
*/

//Code almost same as Q.647 - Palindromic substrings

//------------------------------------------------------------code here----------------------------------------------------------------------------------------//


class Solution {
    public String longestPalindrome(String s) {


        String dp[][]=new String[s.length()][s.length()];

        String w="";

        for(int g=0;g<dp.length;g++)
        {
            for(int i=0,j=g;j<dp[0].length;i++,j++)
            {
                if(g==0) dp[i][j]=s.substring(i,j+1);

                else if(g==1)
                {
                    if(s.charAt(i)==s.charAt(j)) dp[i][j]=s.substring(i,j+1);

                    else dp[i][j]=null;
;
                }

                else
                {
                    if(s.charAt(i)==s.charAt(j) && dp[i+1][j-1]!=null)  dp[i][j]=s.substring(i,j+1);

                    else dp[i][j]=null;
                }

                if(dp[i][j]!=null)
                {
                    w=dp[i][j];  //since we are travelling through the diagonals so all the new strings will be longer than the previous ones 
                }
            }
        }

        return w;
        
    }
}
