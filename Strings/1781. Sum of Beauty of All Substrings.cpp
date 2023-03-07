// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/submissions/910926636/

// Tc -> O(N^2)
//Sc -> O(26) -> O(1)

class Solution {
public:
    int beautySum(string s) {
        int res = 0 , len = s.length();
        for(int i =0;i<len;i++)
        {
            int arr[26] = {0};
            for(int j = i;j<len;j++)
            {
                char ch = s[j];
                arr[ch -'a']++;

                int maxi = INT_MIN,mini = INT_MAX;
                int diff = 0;
                for(int k=0;k<26;k++)
                {
                    maxi = max(maxi,arr[k]);
                    if(arr[k]>0)
                    {
                        mini = min(mini,arr[k]);
                        diff++;
                    }
                }
                if(diff >= 2)
                    res += maxi- mini;
            }
        }
        return res;
    }
};
