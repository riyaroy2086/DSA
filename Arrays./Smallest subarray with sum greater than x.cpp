class Solution{
  public:
    int smallestSubWithSum(int arr[], int n, int x)
    {
        int s=0,i=0,j=0;
        int res = INT_MAX;
        while(i<n)  
        {
            s+=arr[i];
            if(s<=x)
                i++;
            else
            {
               while(s>x)
               {
                   res = min(res,i-j+1);
                   s-=arr[j];
                   j++;
               }
               i++;
            }
        }
        return res;
    }
};
