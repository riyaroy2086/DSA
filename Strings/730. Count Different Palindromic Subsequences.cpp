//https://leetcode.com/problems/count-different-palindromic-subsequences/submissions/941186159/

class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int n=s.size();
        // Creating a 2D array
        long dp[n][n];

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dp[i][j]=0;

        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++)
            {
                if(i==j) 
                    dp[i][j]=1;
                else if(s[i]==s[j])
                {
                    int l=i+1,h=j-1;

                    while(l<j && s[l]!=s[j]) 
                        l++;
                    while(h>i && s[h]!=s[i]) 
                        h--;

                    if(l>h)
                        dp[i][j]=dp[i+1][j-1]*2+2;
                    else if(l==h)
                        dp[i][j]=dp[i+1][j-1]*2+1;
                    else
                        dp[i][j]=dp[i+1][j-1]*2 - dp[l+1][h-1];            
                }
                else
                    dp[i][j]=dp[i][j-1]+dp[i+1][j] -dp[i+1][j-1];    

                if(dp[i][j]<0)
                    dp[i][j]+=1000000007;

                dp[i][j]=dp[i][j]%1000000007;        
            }
        }     
        return dp[0][n-1];   
    }
};
