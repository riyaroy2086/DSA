class Solution {

    public boolean isGood(int n)
    {
        boolean flag=false;
        while(n>0)
        {
            int k=n%10;
            if(k==0 || k==1 || k==8)
            {
                n=n/10;
                continue;
            }

            if(k==2 || k==5 || k==6 || k==9) flag=true;

            else 
            {
                flag=false;
                break;
            }

            n=n/10;
        }
        return flag;
    }

    public int rotatedDigits(int n) {

        int count=0;

        for(int i=1;i<=n;i++)
        {
            if(isGood(i)) count++;
        }

        return count;
    }
}
