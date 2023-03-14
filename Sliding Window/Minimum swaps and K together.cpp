
class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        //no of elements <= k
        int c=0;
        for(int i=0;i<n;i++)
            if(arr[i]<=k)
                c++;
        
        // no of elements greater than k in the window of size = count
        int g=0;
        for(int i=0;i<c;i++)
            if(arr[i]>k)
                g++;
                
        //we can slide the window keep track of element going out from left and coming from right
        int res = g;
        for(int i=0,j=c;j<n;i++,j++)
        {
            if(arr[i]>k)
                g--;
            
            if(arr[j]>k)
                g++;
                
            res = min(g,res);    
        }
        
        return res;
    }
};
