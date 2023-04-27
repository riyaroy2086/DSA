// TC-> O(N) 
// SC-> O(1)

class Solution {
public:
    int maxDepth(string s) {
        int res=0,c=0;
        for(auto ch:s)
        {
            if(ch == '(')
            {
                c++;
                res=max(res,c);
            }
            if(ch ==')') c--;
        }
        return res;
    }
};
