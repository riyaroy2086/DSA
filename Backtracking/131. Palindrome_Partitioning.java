//https://leetcode.com/problems/palindrome-partitioning/

/**
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

 Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]


Example 2:

Input: s = "a"
Output: [["a"]]
*/

//-----------------------------------------------------------------code here------------------------------------------------------------------------------//

class Solution {

    boolean isPalindrome(String str,int start,int end)
    {

        while(start<=end)
        {
            if(str.charAt(start)!=str.charAt(end)) return false;
            start++;
            end--;
        }
        return true;
    }

    void func(String s,int idx,List<String> arr,List<List<String>> ans)
    {
        if(idx==s.length())
        {
            ans.add(new ArrayList<>(arr));
            return;
        }

        for(int i=idx;i<s.length();i++)
        {
            if(isPalindrome(s,idx,i))
            {
                arr.add(s.substring(idx,i+1));
                func(s,i+1,arr,ans);
                arr.remove(arr.size()-1);
            }
        }
    }

    public List<List<String>> partition(String s) {

        if(s == null || s.length() == 0) return new ArrayList<>();

        List<List<String>> ans=new ArrayList<>();
        List<String> arr=new ArrayList<>();

        func(s,0,arr,ans);

        return ans;
        
        
    }
}
