// TC-> O(N^2)
// SC-> O(1)  

class Solution
{
  public:
    long long int substrCount (string s, int k) {
        int c=0,freq[26],n=s.size();
        for(int i=0;i<n;i++)
        {
            int dc=0;
            for(int j=0;j<26;j++)
               freq[j]=0; 
               
            for(int j=i;j<n;j++)
            {
                if(freq[s[j]-'a']==0) dc++;
                
                freq[s[j]-'a']++;
                
                if(dc==k) c++;
                if(dc>k) break;
            }
        }
        return c;
    }
};

// Mapping won't work here
// Testcases failed

class Solution
{
  public:
    long long int substrCount (string s, int k) {
        if(k==0) return 0;
    
        int c=0,j=0,n=s.size();
        unordered_map<char,int> freq;
        
        for(int i=0;i<n;i++)
        {
            freq[s[i]]++; //increasing the freq
            while(freq.size()>k )
            {
                // int p=freq[s[j]]--;
                // if(p==1) 
                freq[s[j]]--;
                if(freq[s[j]]==0)
                    freq.erase(s[j]);
                    
                j++;
            }
            c+=(i-j+1);
        }
        return c;
    }
    
    int exact_k_chars(string &s, int k) {
        return substrCount(s, k) - substrCount(s, k - 1);
}
  
// Sliding window concept
// T.C = O(|s|)
// S.C = O(1)  


class Solution
{
  public:
    long long int substrCount (string s, int k) {
        //if(k==0) return 0;
    return solve(s,k)-solve(s,k-1);
        
    }
    
    long long int solve(string &s, int k)
    {
        int c=0,freq[26]={0},n=s.size();
        long long int res=0;
        int i=0,j=0; // start and end of window

        while(j<n)
        {
            freq[s[j]-'a']++; //increasing the freq
            if( freq[s[j]-'a']==1)
                c++;
                
            //Decreasing the size of window
            while(c>k)
            {
                freq[s[i]-'a']--;
                if(freq[s[i]-'a']==0) 
                    c--;
                i++;    
            }
            j++;
            res=res+(j-i+1);
        }
        return res;
    }
};
  
