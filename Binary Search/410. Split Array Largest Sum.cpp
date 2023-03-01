//https://leetcode.com/problems/split-array-largest-sum/submissions/906809296/

class Solution {
public:
    bool isValid(vector<int> &nums,int k ,int maxSubsum)
    {
        long long subsum =0;
        int c=1;

        for(int i:nums)
        {
            subsum +=i;
            if(subsum>maxSubsum)
            {
                c++;
                subsum = i;
                if(c>k)
                {
                    return false;
                }
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) 
    {
        long long sum =0,max1=0;
        for(long long i:nums)
        {
            max1 = max(max1,i);
            sum+=i;
        }

        long long l =max1,r=sum,m;
        //BS
        while(l<=r)
        {
            m=l+(r-l)/2;
            if(isValid(nums,k,m))
            {
                r=m-1;
            }
            else
            {
                l=m+1;
            }
        }
        return (int)l;
    }
};