//https://leetcode.com/problems/product-of-array-except-self/

class Solution {
    public int[] productExceptSelf(int[] nums) {

        //Optimal solution
        
        int n=nums.length;

        int ans[]=new int[n];

        int p=1;

        for(int i=0;i<n;i++)
        {
            ans[i]=nums[i]*p;   //storing the left cumulative product in the ans array
            p*=nums[i];
        }

        p=1;

        for(int i=n-1;i>0;i--)   //i>0 and not ">=" to avoid edge cases
        {
            ans[i]=ans[i-1]*p;   //multiplying the left cumulative product with the right
            p*=nums[i];          //simultaneously calculating the right cumulative product
        }

        ans[0]=p;              

        return ans;
        

//*****************************************************************************************//  

        //Brute force solution (TLE)

        /*
        Arrays.fill(ans,1);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j) ans[i]*=nums[j];
            }
        }

        return ans;

        */

    }
}
