
class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        string res="";
        // first string
        string first = arr[0];
        
        // iterating thru the first
        for(int i=0;i<first.size();i++)
        {
            char ch = first[i];
            int c=0;
            
            // now checking other strings in the vector
            for(int j=1 ;j<N;j++)
            {
                string s = arr[j];
                if(i<s.size() && ch==s[i]) c++;
                else break;
            }
            if(c==N-1)
                res+=ch;
                
            else break;    
        }
        if(res.empty())
            return "-1";
            
        return res;
    }
};
