class Solution{
  public:
    int atoi(string str) {
        int num=-1,i=0;
        while(str[i] && str[i] >='0' && str[i] <= '9')
        {
            num=num*10+(str[i]-'0');
            i++;
        }
        
        return num;
    }
};

//-------------------------------------------------------------


class Solution
{
  public:
    long long int substrCount (string s, int k) {
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
