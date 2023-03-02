//https://leetcode.com/problems/longest-happy-prefix/submissions/907878087/

class Solution {
public:
    //Tc -> O(N)
    //Sc -> O(1)
    string longestPrefix(string s) {
        long l=0,r=0,mul=1;
        long mod = 1000000007;
        long len=0;
        // int l = "";
        //int i,j;
        for(int i=0,j=s.size()-1;i<s.size(),j>0;i++,j--)
        {
            int fst = s[i]-'a' , lst = s[j] -'a';
            l = (l*26+fst) % mod;
            r = (r+mul*lst) % mod;
            mul = mul*26 % mod;
            if(l==r)
                len = i+1;
        }
        return s.substr(0,len);
    }
};
