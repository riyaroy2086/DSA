//https://leetcode.com/problems/generate-parentheses/description/

class Solution {


    void func(ArrayList<String> arr,int n,int open,int close,String s)
    {
        if(s.length()==n*2)
        {
            arr.add(s);
            return;
        }

        if(open<n)  func(arr,n,open+1,close,s+"(");

        if(open>close)  func(arr,n,open,close+1,s+")");
    }

    public List<String> generateParenthesis(int n) {

        ArrayList<String> arr=new ArrayList<String>();

        func(arr,n,0,0,"");

        return arr;


        
    }
}
