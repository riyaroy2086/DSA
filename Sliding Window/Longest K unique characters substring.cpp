class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int res=-1,n=s.size();
        int x=0;
        unordered_map<char,int> m;
        
        for(int j=0,i=0;j<n;j++)
        {
            //storing in the map
            m[s[j]]++;
            //if mapped
            // if(m[s[j]]==1)
            // {
            //     x++;
            // }
            if(m.size()==k)
                res = max(res,j-i+1);
            while(m.size()>k && i<n)
            {
                m[s[i]]--;
                //decreasing the right window
                if(m[s[i]]==0)
                {
                    m.erase(s[i]);
                }
                i++;
            }
            //res = max(res,j-i+1);
        }
        return res;
    }
};
