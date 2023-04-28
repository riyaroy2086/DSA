// Tc-> O(N) Sc-> O(N)

class Solution {
public:
//Based on KMP algorithm and LPS array
    int minChar(string str){
        string rev="";
        int n=str.size();
        for(int i=n-1;i>=0;i--)
            rev+=str[i];
            
	   // int v[n];
	   // v[0]=0;
	   vector<int> v(2*n,0);
	    int len=0,i=1;
	    while(i<n)
	    {
	        if(str[i]==str[len])
	        {
	            len++;
	            v[i]=len;
	            i++;
	        }
	        else
	        {
	            if(len!=0)
	            {
	                len=v[len-1];
	            }
	            else
	            {
	                //v[i]=0;
	                i++;
	            }
	        }
	    }
	    i=0;
	    len=0;
	    while(i<n)
	    {
	        if(rev[i] ==str[len])
	        {
	            v[i+n] = ++len;
	            i++;
	        }
	        else
	        {
	            if(len!=0)
	                len=v[len-1];
	            
	           else i++; 
	        }
	    }
	    return n - v[2*n-1];
    }
};
