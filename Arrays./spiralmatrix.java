class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
List<Integer> a = new ArrayList<>();
        int T,B,L,R,dir;
        T=0;
        B=matrix.length-1;
        L=0;
        R=matrix[0].length-1;
        dir=0;
        int i;


        while(T<=B && L<=R)
        {
            if(dir==0)
            {
                for(i=L;i<=R;i++)
                    a.add(matrix[T][i]);
                T++;
            }
            else if(dir==1)
            {
                for(i=T;i<=B;i++)
                   a.add(matrix[i][R]);
                R--;
            }
            else if(dir==2)
            {
                for(i=R;i>=L;i--)
                    a.add(matrix[B][i]);
                B--;
            }
            else if(dir==3)
            {
                for(i=B;i>=T;i--)
                    a.add(matrix[i][L]);
                L++;
            }
            dir=(dir+1)%4;
        }
        return a;
    }
}
