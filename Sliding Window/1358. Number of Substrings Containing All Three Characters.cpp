class Solution {
public:
    int numberOfSubstrings(string s) {
        //using sliding window
        // int i,j;
        // int res =0;
        //using unordered_map
        int l=0,r=0,n=s.size()-1,c=0;
        unordered_map<char,int> m ;
        while(r<s.size())
        {
            m[s[r]]++; // adding the char at the right end
            while(m['a']>=1 && m['b']>=1 && m['c']>=1)
            {
                c+=1+(n-r);
                m[s[l]]--;
                l++;
            }
            r++;
        }
        return c;

    }
    
};
