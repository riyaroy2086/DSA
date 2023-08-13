//https://leetcode.com/problems/basic-calculator-ii/

/*
Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().


Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5
*/


class Solution {
    public int calculate(String s) {

        if(s.length()==0 || s==null) return 0;

        Stack<Integer> stack=new Stack<>();

        int num=0,val=0;
        char op='+';

        for(int i=0;i<s.length();i++)
        {
            char c=s.charAt(i);

            if(Character.isDigit(c))
            {
                num=(num*10)+Character.getNumericValue(c);            //forming the digit that may be more than 9
            }

            if(!Character.isDigit(c) && c!=' ' || i==s.length()-1)   //considering the last character
            {
                if(op=='+') stack.push(num);

                else if(op=='-') stack.push(-num);

                else if(op=='*') stack.push(stack.pop()*num);

                else if(op=='/') stack.push(stack.pop()/num);

                num=0;
                op=s.charAt(i);
            }
        }

        while(!stack.isEmpty())
        {
            val+=stack.pop();
        }
        
        return val;
    }
}
