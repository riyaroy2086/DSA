//https://leetcode.com/problems/isomorphic-strings/submissions/907843969/

  //TC -> O(N)
  //Sc -> O(1)

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> si(128);
        vector<int> ti(128);

        for(int i=0;i<s.length();i++)
        {
            if(si[s[i]] != ti[t[i]])
                return false;
            // increment the si and ti by 1
            si[s[i]] = i+1;
            ti[t[i]] = i+1;    
        }
        return true;
    }
};
