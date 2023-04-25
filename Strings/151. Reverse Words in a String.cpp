// https://leetcode.com/submissions/detail/939439701/

class Solution {
public:
    string reverseWords(string s) {
        string res;
        int i=0,n=s.size();
        while(i<n)
        {
            if(s[i] == ' ')
                i++;
            else
            {
                string ans;
                while(i<n && s[i] !=' ')
                {
                    ans+=s[i];
                    i++;
                }
                if(res.size() == 0)
                    res = ans;
                else
                    res= ans+ " " + res;   
            }    
        }
        return res;
    }
};
