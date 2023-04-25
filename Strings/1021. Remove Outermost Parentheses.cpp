https://leetcode.com/submissions/detail/939423765/

class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int c=0;

        for(char ch : s)
        {
            if(ch =='(' && c++>0)
                res+=ch;
            if(ch ==')' && c-->1)
                res+=ch;    
        }
        return res;
    }
};
