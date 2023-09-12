//https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

/**
A string s is called good if there are no two different characters in s that have the same frequency.

Given a string s, return the minimum number of characters you need to delete to make s good.

The frequency of a character in a string is the number of times it appears in the string. 
For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.

 
Example 1:

Input: s = "aab"
Output: 0
Explanation: s is already good.


Example 2:

Input: s = "aaabbbcc"
Output: 2
Explanation: You can delete two 'b's resulting in the good string "aaabcc".
Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".


Example 3:

Input: s = "ceabaacb"
Output: 2
Explanation: You can delete both 'c's resulting in the good string "eabaab".
Note that we only care about characters that are still in the string at the end (i.e. frequency of 0 is ignored).
*/

//-----------------------------------------------------------------------code here-------------------------------------------------------------------------//


class Solution {
    public int minDeletions(String s) {

        HashMap<Character,Integer> map=new HashMap<>();

        ArrayList<Integer> arr=new ArrayList<>();

        for(char c:s.toCharArray())
        {
            map.put(c,map.containsKey(c)?map.get(c)+1:1);
        }

        System.out.println(map);
        
        for(Character c:map.keySet())
        {
            arr.add(map.get(c));
        }

        Collections.sort(arr);

        int currMaxFreq=arr.get(arr.size()-1);  //to check the required range for the next frequency

        int count=0;

        for(int i=arr.size()-1;i>=0;i--)
        {
            if(arr.get(i)>currMaxFreq)
            {
                if(currMaxFreq>0) count+=(arr.get(i)-currMaxFreq);

                else count+=arr.get(i);   //currMaxFreq < 0 means all the next characters needs to be deleted
            }

            currMaxFreq=Math.min(arr.get(i)-1,currMaxFreq-1);   

        }

        return count;
    }
}
