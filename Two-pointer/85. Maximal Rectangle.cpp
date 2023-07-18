// PROBLEM STATEMENT --------------------------->

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:

Input: matrix = [["1"]]
Output: 1
 

Constraints:

rows == matrix.length
cols == matrix[i].length
1 <= row, cols <= 200
matrix[i][j] is '0' or '1'.


// SOLUTION ------------------------------------------------>

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // int r = matrix.size() , c = matrix[0].size();
        // int maxA = 0;

        // vector<vector<int>> dp(r,vector<int> (c,0));

        // for(int i=0;i<r;++i)
        // {
        //     for(int j=0;j<c;++j)
        //     {
        //         if(matrix[i][j] == 1)
        //         {
        //             if(i==0 || j==0)
        //                 dp[i][j] = 1;
        //             else
        //                 dp[i][j] = max(dp[i-1][j],dp[i][j-1])+1;    
        //         }
                
        //     }
        // }

        // for(int i=0;i<r;++i)
        // {
        //     for(int j=0;j<c;++j)
        //     {
        //         maxA = max(maxA,dp[i][j]);
        //     }
        // }

        // return maxA;



        
    }
};

// TIME AND SPACE C ------------------------------------------------->


// SUBMISSION ------------------------------------------>

