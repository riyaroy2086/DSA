There is a strange printer with the following two special properties:

The printer can only print a sequence of the same character each time.
At each turn, the printer can print new characters starting from and ending at any place and will cover the original existing characters.
Given a string s, return the minimum number of turns the printer needed to print it.

 

Example 1:

Input: s = "aaabbb"
Output: 2
Explanation: Print "aaa" first and then print "bbb".
Example 2:

Input: s = "aba"
Output: 2
Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.
 

Constraints:

1 <= s.length <= 100
s consists of lowercase English letters.

// SOLUTION ---------------------------------------->

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        //We then create a 2D vector dp of size n x n, initialized with all zeros.
        vector<vector<int>> dp(n,vector<int> (n,0));
        for(int i=n-1;i>=0;--i)
        {
            dp[i][i] = 1; // the minimum number of operations required to print the substring of length

            for(int j=i+1;j<n;++j) // The outer loop (i) represents the starting index of the substring, and the   inner loop (j) represents the ending index of the substring.
            {
                if(s[i]==s[j])
                    dp[i][j] = dp[i][j-1]; //minimum number of operations needed to print the substring s[i+1:j], which is dp[i][j-1].
                else
                {
                    dp[i][j] = INT_MAX;
                    for(int k=i;k<j;++k)
                        dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]);
                        // If s[i] and s[j] are different characters, we consider all possible break points k within the substring and find the minimum number of operations needed to print both halves of the substring s[i:j]. The total number of operations will be the sum of the minimum number of operations needed for the two halves. We iterate through all possible k values to find the optimal split.
                }                                             
            }
        }
        return dp[0][n-1];
    }
};

//https://leetcode.com/problems/strange-printer/submissions/1007647904/
