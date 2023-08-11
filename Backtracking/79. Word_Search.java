//https://leetcode.com/problems/word-search/description/

class Solution {

    boolean exists(char[][] board,String word,int i,int j,int pos)
    {       
        if(pos==word.length()) return true;

        if(i<0 || j<0 || i>=board.length || j>=board[0].length) return false;

        if(board[i][j]!=word.charAt(pos)) return false;

        char temp=board[i][j];
        board[i][j]='*';

        if(exists(board,word,i+1,j,pos+1) ||
            exists(board,word,i-1,j,pos+1) ||
            exists(board,word,i,j+1,pos+1) ||
            exists(board,word,i,j-1,pos+1)
            ) return true;

        board[i][j]=temp;  //backtracking condition

        return false;

        
        
    }

    public boolean exist(char[][] board, String word) {

        for(int i=0;i<board.length;i++)
        {
            for(int j=0;j<board[0].length;j++)
            {
                if(board[i][j]==word.charAt(0) && exists(board,word,i,j,0)) return true;
            }
        }

        return false;
        
    }
}
