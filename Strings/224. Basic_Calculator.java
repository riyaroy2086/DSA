//https://leetcode.com/problems/basic-calculator/

/*
Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "1 + 1"
Output: 2
Example 2:

Input: s = " 2-1 + 2 "
Output: 3
Example 3:

Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23 
*/

class Solution {

    public int calculate(String s) {
        
        int value=0,sign=1;

        Stack<Integer> stack=new Stack<>();

        for(int i=0;i<s.length();i++)
        {
            char c=s.charAt(i);

            if(Character.isDigit(c))
            {
                int nums=0;
                while(i<s.length())
                {
                     if(!Character.isDigit(s.charAt(i)))
                        break;
                    nums=(nums*10)+Character.getNumericValue(s.charAt(i));
                    i++;
                }
                value+=nums*sign;
                i--;
                
            }

            else if(c=='+')
            {
                sign=1;
            }
            else if(c=='-')
            {
                sign=-1;
            }

            else if(c=='(')
            {
                stack.push(value);
                stack.push(sign);
                value=0;
                sign=1;
            }

            else if(c==')')
            {
               value*=stack.pop();
               value+=stack.pop();
            }

        }

        return value;
        
    }
}
