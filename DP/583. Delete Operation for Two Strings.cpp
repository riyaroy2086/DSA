// Using 2-D DP array
class Solution {   
public:
    int minDistance(string word1, string word2) {
        int s1 = word1.size(), s2 = word2.size(); 
        vector<vector<int>> dp (s1+1,vector<int> (s2+1,0));

        for(int i=0;i<=s1;i++)
        {
            for(int j=0;j<=s2;j++)
            {
                if(i==0 || j ==0)
                    dp[i][j] = i+j;
                else if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1+min(dp[i][j-1],dp[i-1][j]);      
            }
        }
        return dp[s1][s2];    
    }

};

// Time Complexity -> O(s1*s2)
// Space Complexity -> O(s1*s2)


// Using 1D DP array
class Solution {   
public:
    int minDistance(string word1, string word2) {
        int s1 = word1.size(), s2 = word2.size(); 
        vector<int> dp (s2+1);

        for(int i=0;i<=s1;i++)
        {
            vector<int> temp (s2+1);
            for(int j=0;j<=s2;j++)
            {
                if(i==0 || j ==0)
                    temp[j] = i+j;
                else if(word1[i-1] == word2[j-1])
                    temp[j] = dp[j-1];
                else
                    temp[j] = 1+min(dp[j],temp[j-1]);      
            }
            dp=temp;
        }
        return dp[s2];    
    }

};

// Time Complexity -> O(s1*s2)
// Space Complexity -> O(s2)
  
  
