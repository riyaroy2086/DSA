//https://leetcode.com/problems/pascals-triangle-ii/

/**
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]


Example 2:

Input: rowIndex = 0
Output: [1]


Example 3:

Input: rowIndex = 1
Output: [1,1]
*/

//--------------------------------------------------------------------code here----------------------------------------------------------------------------//

class Solution {
    public List<Integer> getRow(int rowIndex) {

        List<Integer> curr=new ArrayList<>();
        List<Integer> prev=new ArrayList<>();

        for(int i=0;i<=rowIndex;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j==0 || j==i) curr.add(1);

                else curr.add(prev.get(j-1)+prev.get(j));
            }

            prev=curr;
            curr=new ArrayList<>();
        }

        return prev;
        
    }
}
