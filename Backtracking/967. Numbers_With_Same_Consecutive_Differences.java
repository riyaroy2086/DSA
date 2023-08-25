//https://leetcode.com/problems/numbers-with-same-consecutive-differences/

/**
Given two integers n and k, return an array of all the integers of length n where the difference between every two consecutive digits is k. You may return the answer in any order.
Note that the integers should not have leading zeros. Integers as 02 and 043 are not allowed.

Example 1:

Input: n = 3, k = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.


Example 2:

Input: n = 2, k = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
*/

//----------------------------------------------------------------------------code here-----------------------------------------------------------------------//


//Optimised solution

//used Backtracking

class Solution {

    void dfs(int n,int k,int curr,int prev,int idx,ArrayList<Integer> arr)
    {

        if(idx==n-1)
        {
            arr.add(curr);
            return;
        }

        int next=prev+k;

        if(next<10)
            dfs(n,k,(curr*10)+next,next,idx+1,arr);

        next=prev-k;

        if(k!=0 && next>=0)     //since (prev-k) can go in negetive 
            dfs(n,k,(curr*10)+next,next,idx+1,arr);


    }

    public int[] numsSameConsecDiff(int n, int k) {

        if(n==1) return new int[]{0,1,2,3,4,5,6,7,8,9};

        ArrayList<Integer> arr=new ArrayList<>();

        for(int i=1;i<=9;i++)
            dfs(n,k,i,i,0,arr);
        
        int ans[]=new int[arr.size()];

        for(int i=0;i<arr.size();i++)
        {
            ans[i]=arr.get(i);
        }

        return ans;
                        


        //--------------------------------------------Brute Force------------------------------------//
        
        //Checking all digits in the range

        //TLE

        // int start=(int)Math.pow(10,n-1);
        // int end=(int)Math.pow(10,n)-1;

        // ArrayList<Integer> arr=new ArrayList<>();
        // int c=0;

        // for(int i=start;i<=end;i++)
        // {
        //     int cp=i;
        //     int s=0;

        //     int digits[]=new int[n];

        //     while(cp>0)
        //     {
        //         int r=cp%10;
        //         if(s<n) digits[s++]=r;
        //         cp=cp/10;
        //     }

        //     boolean flag=true;

        //     for(int j=1;j<n;j++)
        //     {
        //         if(Math.abs(digits[j-1]-digits[j])!=k)
        //         {
        //             flag=false;
        //             break;
        //         }  
        //     }
        //     if(c<n && flag) arr.add(i);
        // }

        // int ans[]=new int[arr.size()];

        // for(int i=0;i<arr.size();i++)
        // {
        //     ans[i]=arr.get(i);
        // }

        // return ans;
        
    }
}
