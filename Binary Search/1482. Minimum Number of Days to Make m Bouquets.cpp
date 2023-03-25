//https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/submissions/921705250/

class Solution {
public:
    bool func(vector<int>& bloomDay,int m, int k, int mid)
    {
        int count=0, sum=0;
        int n = bloomDay.size();
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid){ // the flower has bloomed
                count++;
                if(count==k){ // a single bouquet can be formed
                    sum++;
                    count=0; // c =0 for the next bouquet
                }
            }else count=0; // the flower has not bloomed
        }
        if(sum>=m) return true; 

        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l =0;
        int r = *max_element(bloomDay.begin(),bloomDay.end());
        int res = -1;
        // binary search
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(func(bloomDay,m,k,mid))
            {
                res=mid;
                r=mid-1;
            }else l=mid+1;
        }
        return res;
    }
};
