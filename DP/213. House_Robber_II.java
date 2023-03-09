class Solution {

    public int amt(int arr[],int n,int dp[])
    {
        if(n==0) return arr[n];
        if(n<0) return 0;

        if(dp[n]!=-1) return dp[n];

        int pick=arr[n]+amt(arr,n-2,dp);
        int notpick=amt(arr,n-1,dp);

        return dp[n]=Math.max(pick,notpick);


    }


    public int rob(int[] nums) {

        int n=nums.length;

        if(n==1)
            return nums[0];

        int arr1[]=new int[n-1];
        int arr2[]=new int[n-1];

        int a=0,b=0;

        for(int i=0;i<n;i++)   //Dividing the array into two halves
        {
            if(i!=n-1) arr1[a++]=nums[i];   //One without the last element

            if(i!=0) arr2[b++]=nums[i];     //One without the first element
        }

        //had to use two dp arrays as there was some issue with the memory allocation

        int dp1[]=new int[n-1];   
        int dp2[]=new int[n-1];

        //Using the memoization approach
        
        Arrays.fill(dp1,-1);
        Arrays.fill(dp2,-1);

        return Math.max(amt(arr1,n-2,dp1),amt(arr2,n-2,dp2));
        
    }
}
