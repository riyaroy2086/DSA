//https://leetcode.com/problems/word-break/

/**
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".


Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.


Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
*/

//-------------------------------------------------------------------code here-----------------------------------------------------------------------------//

class Solution {

    int func(String s, List<String> wordDict,int i,int dp[])
    {
        if(i==s.length()) return 1;

        if(dp[i]!=-1) return dp[i];

        String w="";

        for(int j=i;j<s.length();j++)
        {
            w+=s.charAt(j);

            if(wordDict.contains(w)) 
            {
                if(func(s,wordDict,j+1,dp)==1) return dp[i]=1;
            }
            
        }

        return dp[i]=0;

    }

    public boolean wordBreak(String s, List<String> wordDict) {

       int dp[]=new int[s.length()];

       Arrays.fill(dp,-1);

       return func(s,wordDict,0,dp)==1;

    }
}
