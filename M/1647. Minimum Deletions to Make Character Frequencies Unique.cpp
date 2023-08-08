A string s is called good if there are no two different characters in s that have the same frequency.

Given a string s, return the minimum number of characters you need to delete to make s good.

The frequency of a character in a string is the number of times it appears in the string. For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.

 

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
 

Constraints:

1 <= s.length <= 105
s contains only lowercase English letters.

// SOLUTION-->>>

class Solution {
public:
    int minDeletions(string s) {
        int res = 0;
        vector<int> c(26); // to count 26 english alphabets
        unordered_set<int> freq;
        for(auto ch :s)
            ++c[ch-'a'];
        
        // to count the min deletions reqd
        for(auto i : c)
        {
            while(i>0 && !freq.insert(i).second)
            {
                --i; // decrement one occurance of the char 
                ++res; // increse the no. of deletions
            }
        }
        return res;
    }
};

// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/submissions/1015822208/
