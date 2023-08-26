//https://leetcode.com/problems/repeated-substring-pattern/

/**
Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

Example 1:

Input: s = "abab"
Output: true
Explanation: It is the substring "ab" twice.


Example 2:

Input: s = "aba"
Output: false


Example 3:

Input: s = "abcabcabcabc"
Output: true
Explanation: It is the substring "abc" four times or the substring "abcabc" twice.
*/

//----------------------------------------------------------------------code here----------------------------------------------------------------------------//

class Solution {
    public boolean repeatedSubstringPattern(String s) {

        //Approach 1:- 

        //Optimised

        //String manipulation

        /**
        Basic intuition: We need to check if a string can be constructed using substring, so if we create a new string by concatinating 
        the original string twice and remove the first and last element then the newly formed string should contain the original string 
        as a sub-string inorder to satisfy the required condition.  
         */

        String newStr=s+s;

        return (newStr.substring(1,newStr.length()-1)).contains(s);

        


        //-------------------------------------------------------------------------------------------------------------------------------------------------//


        //Approach 2:

        //Not optimised

        /**
        Basic intuition :- The length of the substring(l) shall always be less than or equal to the half of the original string length(n) and 
        for the required condition to be true 'n' shall be perfectly divisible by 'l' i.e the original string shall be a multiple of the sub-string. 
         */

        //  boolean flag=false;

        //  int n=s.length();

        //  for(int i=1;i<=(n/2);i++)
        //  {
        //      if((n%i)==0)
        //      {
        //          int times=n/i;
        //          String newStr="";

        //          while(times>0)
        //          {
        //              newStr+=s.substring(0,i);
        //              times--;
        //          }

        //          if(newStr.equals(s))
        //          {
        //              flag=true;
        //              break;
        //          }
        //      }
        //  }

        //  return flag;
        
        
    }
}
