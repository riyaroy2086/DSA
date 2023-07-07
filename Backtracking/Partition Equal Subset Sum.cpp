Partition Equal Subset Sum
MediumAccuracy: 30.24%Submissions: 173K+Points: 4
Sharpen up your programming skills, participate in coding contests & explore high-paying jobs

Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explanation: 
The two parts are {1, 5, 5} and {11}.
Example 2:

Input: N = 3
arr = {1, 3, 5}
Output: NO
Explanation: This array can never be 
partitioned into two such parts.

Your Task:
You do not need to read input or print anything. Your task is to complete the function equalPartition() which takes the value N and the array as input parameters and returns 1 if the partition is possible. Otherwise, returns 0.


Expected Time Complexity: O(N*sum of elements)
Expected Auxiliary Space: O(N*sum of elements)


Constraints:
1 ≤ N ≤ 100
1 ≤ arr[i] ≤ 1000
N*sum of elements ≤ 5*106


//-----------------------------------------------------------Solution--------------------------------------------------------------------------------//


class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i;i<N;++i)
            sum += arr[i];
        //if sum is odd-> array can;t be aprtitioned
        if(sum%2 != 0) return false;
        
        //subset with the sum = s/2
        int l =0,r=sum/2;
        while(l<=r) //binary search TC-> O(logN)
        {
            int mid = l +(r-l)/2;
            if(subsetSum(arr,N,mid))
            {
                return true;
            }else r = mid-1;
        }
        return false;
    }
    
    bool subsetSum(int arr[],int N,int sum)
    {
        if(sum==0) return true;
        if(N==0) return false;
        
        //inc the curr element
        if(arr[N-1] <= sum)
            return subsetSum(arr,N-1,sum-arr[N-1]);
        
        //exc the curr element
        return subsetSum(arr,N-1,sum); 
    }
};
