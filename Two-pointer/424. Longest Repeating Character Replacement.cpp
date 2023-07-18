// PROBLEM STATEMENT -------------------------------------------->

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achive this answer too.
 

Constraints:

1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length


// SOLUTION-------------------------------->

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, r=0;
        int maxC = 0 , res =0;
        int len = s.size();
        vector<int> v(128);

        for(r=0;r<len;++r)
        {
            maxC = max(maxC,++v[s[r]]); // incrementing the count of the curr character in v
            while(maxC+k < r-l+1)
                {
                    --v[s[l]];
                    l++;
                }
                res = max(res,r-l+1);
        }
        return res;
    }
};


// TIME AND  SPACE COMPLEXITY ---------------------------------------------->

Time complexity: The outer loop iterates over all the characters in the string s, 
which takes a time of O(n). The inner loop iterates over the sliding window, which has a size of at most n. 
The number of times the inner loop iterates is at most n, so the total time complexity of the code is O(n + n) = O(n).


Space complexity: The only additional space used is the vector v, which has a size of 128. 
The size of the vector is independent of the length of the string s, so the space complexity of the code is O(1)

// SUBMISSION ------------------------------------------------->

//https://leetcode.com/problems/longest-repeating-character-replacement/submissions/997434920/