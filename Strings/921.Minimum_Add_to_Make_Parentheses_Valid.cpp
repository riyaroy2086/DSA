//https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/submissions/907851195/

class Solution {
public:
 // Tc -> O(N)
 // Sc-> O(1)
    int minAddToMakeValid(string s) {
        // vector<string> res();
        // int c1 =0;
        int l = 0, r = 0;
        for(char ch : s)
        {
            // res.push_back(s[i]);
            if(ch =='(')
                l++;
            else
            {
                if(l==0)
                    r++; // if ")" comes first i.e.e before ")" or any of such complicated cases
                else
                    l--;
            }    
        }
        return l+r;
    }
};
