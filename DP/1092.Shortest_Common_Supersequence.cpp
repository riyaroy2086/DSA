// https://leetcode.com/problems/shortest-common-supersequence/submissions/904759206/

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(),m = str2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        //LCS=> Least Common Subsequence
        //filling the 0th rows and cols w/ zeros
        int i=0;
        for(;i<=n;i++)
            dp[i][0] = 0;

        for(;i<=m;i++)
            dp[0][i] = 0; 

        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=m;k++)
            {
                if(str1[j-1] == str2[k-1]) //LCS 
                    dp[j][k] = 1+dp[j-1][k-1];
                else // not LCS
                    dp[j][k] = 0+max(dp[j-1][k],dp[j][k-1]);    
            }
        }    

        int len = dp[n][m]-1;
        int j = n,k=m; // Traversing in the reverse order
        string res = "";

        while(j>0 && k>0)
        {
            if(str1[j-1]==str2[k-1]){
                res += str1[j-1];
                len--;
                j--;
                k--;
            }else if(dp[j-1][k]>dp[j][k-1]){
                res+= str1[j-1];
                j--;
            }else{
                res+=str2[k-1];
                k--;
            }
        }

        // Adding the remaing chars
        while(j>0)
        {
            res+=str1[j-1];
            j--;
        }
        while(k>0)
        {
            res+=str2[k-1];
            k--;
        }
        reverse(res.begin(),res.end());
        return res; 
    }
};
