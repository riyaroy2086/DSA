class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k >= prices.size()/2)
        {
            int buy = INT_MIN,sell=0;
            for(int i: prices)
            {
                    sell = max(sell,buy+i);
                    buy = max(buy,sell-i);
            }
            return sell;
        }

        vector<int> sell(k+1);
        vector<int> buy(k+1,INT_MIN);

        for(int j: prices)
        {
            for(int i=k;i>0;i--)
            {
                sell[i] = max(sell[i],buy[i]+j);
                buy[i] = max(buy[i],sell[i-1]-j);
            }
        }
        return sell[k];
    }
};
