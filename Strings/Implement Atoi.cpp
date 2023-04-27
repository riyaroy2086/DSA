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

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        int res=0,sign=1,i=0,n=str.size();
        
        if(str[0]=='-')
        {
            i=1;
            sign=-1;
        }
        
        for(;i<n;i++)
        {
            int temp=str[i]-'0';// removing the zeros if any
            //maintainfg non-no. char
            if(temp>9 ||temp<0) return -1;
            
            res=res*10+temp;
        }
        return (sign*res);
    }
};
