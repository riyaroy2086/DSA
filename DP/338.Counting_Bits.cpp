338. Counting Bits
Easy

Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

Example 1:

Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
 

Constraints:

0 <= n <= 105

Solution :

class Solution {
public:
    vector<int> countBits(int n) {
        //----------------------------------------------- O(nlogn) solution---------------------------------------------------//
        // vector<int> dp;
        // // n+1 steps so iterating upto n steps
        // for(int i=0;i<=n;++i)
        // {
        //     int sum = 0; // identity element initialization
        //     int it = 1;

        //     while(it!=0)
        //     {
        //         sum += it%2;
        //         it/=2;      
        //     }
        //     dp.push_back(sum);
        // }
        // return dp;

        //----------------------------------------------- O(n) solution---------------------------------------------------//

        vector<int> dp(n+1);
        // 0 bit = 0 
        dp[0]=0;

        //Number of set bits in X - Number of set bit in Y <= 1
        //i%2 will be 0 for even number ans 1 for odd number
        // if X is ODD
        
        // then the (LSB) Least Significant Bit will always be set and dividing by 2 means right shifting the number by 1 bit.
        // so if last bit is set and right shift it by 1 bit than the last set bit will be lost.
        // therfore the new number Y has 1 set bit less than in compare to X
        // But if X is Even
        
        // then LSB will be equal to 0, therefore even we do right shift by1 bit then only this 0 bit will be lost and no set bit got lost
        // so When we have X has Even,
        
        // no of set bit in X = no of set bit in Y
        // and When X is ODD
        
        // no of set bit in X = 1 + no of set bit in Y
        for(int i=1;i<=n;++i)
           dp[i]=dp[i/2] + i%2;
   
        return dp;   
    }
};


