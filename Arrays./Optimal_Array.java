class Solution {
    public long[] optimalArray(int n,int a[])
    {
        long arr[]=new long[n];
        
        arr[0]=0;   //since no operations are required for the single element array
        
        for(int i=1;i<n;i++)
        {
            arr[i]=arr[i-1]+(a[i]-a[i/2]);  
            
        //Here for i-th element minimum (i-1) calculations need to be done
        //along with the number of (i-th element - median element) number of calculations 
        }
        return arr;
    }
}
