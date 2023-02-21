class Solution {
public:
    
    // int getMaxProfit(vector<int> &prices, int left, int right)
    // {
    //     // edge case
    //     if(left >= right)
    //         return 0;

    //     int currPro = 0, pro =0;
    //     for(int i=0;i<=right;i++)
    //     {
    //         for(int j = i+1;j<= right;j++)
    //         {
    //             if(prices[j]>prices[i])
    //             {
    //                 currPro= prices[j]-prices[i]+getMaxProfit(prices,left,i-1)+getMaxProfit(prices,j+1,right);
    //             }
    //             pro=max(currPro,pro);
    //         }
    //     }
    //     return pro;
    // }
    int maxProfit(vector<int>& prices) 
    {
        int currPro = 0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]> prices[i-1])
                currPro+= prices[i]-prices[i-1];
        }
        //return getMaxProfit(prices,0,prices.size()-1);
        return currPro;
    }
};