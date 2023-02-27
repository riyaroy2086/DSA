// Sliding Window Problem
// TC -> O(n)
// SC -> O(1)

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0;
        int maxCount =0;
        int res =0;
        vector<int> v(128);

        for(r=0;r<s.size();r++)
        {
            maxCount = max(maxCount,++v[s[r]]);
            while(maxCount+k < r-l+1)
            {
                --v[s[l++]];
            }
            res = max(res,r-l+1);
        }
        return res;
    }
};

