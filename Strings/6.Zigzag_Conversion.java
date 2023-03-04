class Solution {
    public String convert(String s, int numRows) {
        
        int i=0;
        String  a[]=new String[numRows];
        boolean f=false;
        String ans="";

        if(numRows==1)
        {
            return s;
        }
        
        for(int k=0;k<numRows;k++)
        {
            a[k]=""; //Initializing every arrray element with an empty string to avoid null value
        }

        for(char c:s.toCharArray())
        {
           // System.out.println(c);
            a[i]+=c;

            if(i==0 || i==(numRows-1))
            {
                f=!f;        //Toggling the flag to keep records of the first and last rows
            }
            if(f)
            {
                i++;
            }
            else
            {
                i--;
            }
        }

        for(String w:a)
        {
                ans+=w;
        }
        return ans;
        
    }
}
