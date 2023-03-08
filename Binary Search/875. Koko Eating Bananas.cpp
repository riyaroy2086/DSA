//https://leetcode.com/problems/koko-eating-bananas/submissions/911374684/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        //maximum number of bananas in any pile = r pointer
        int l = 1,r = *max_element(piles.begin(),piles.end());
        while(l<r)
        {
            int mid = l+(r-l)/2;
            if(allEaten(piles,mid,h)) 
                r = mid;
            else
                l = mid+1;    
        }
        return l; // min k
    }

    bool allEaten(vector<int> & piles, int mid, int h)
    {
        int t = 0;
        for(auto i : piles) {
            //updating the time till all the bananas per hour are done
            t += (i-1)/mid+1;
            if(t>h)
                return false;   
        }
        return true; 
    }
};
