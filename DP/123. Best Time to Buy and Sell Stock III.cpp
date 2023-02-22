class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int holdOne = INT_MAX,holdTwo = INT_MAX;
        int sellOne = 0, sellTwo = 0;
        int n = prices.size();
        for(int i=0;i<n;i++)
        {  
            holdOne= min(holdOne,prices[i]);
            sellOne = max(sellOne,prices[i]-holdOne);
            holdTwo = min(holdTwo,prices[i]-sellOne);
            sellTwo = max(sellTwo,prices[i]-holdTwo);
        }
        return sellTwo;
    }
};
