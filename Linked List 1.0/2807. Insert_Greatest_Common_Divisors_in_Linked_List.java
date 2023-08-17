//https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/

/**
Given the head of a linked list head, in which each node contains an integer value.
Between every pair of adjacent nodes, insert a new node with a value equal to the greatest common divisor of them.
Return the linked list after insertion.

The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.

 
Example 1:

Input: head = [18,6,10,3]
Output: [18,6,6,2,10,1,3]
Explanation: The 1st diagram denotes the initial linked list and the 2nd diagram denotes the linked list after inserting the new nodes (nodes in blue are the inserted nodes).
- We insert the greatest common divisor of 18 and 6 = 6 between the 1st and the 2nd nodes.
- We insert the greatest common divisor of 6 and 10 = 2 between the 2nd and the 3rd nodes.
- We insert the greatest common divisor of 10 and 3 = 1 between the 3rd and the 4th nodes.
There are no more adjacent nodes, so we return the linked list.
*/

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

//Code

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {

    int findGcd(int x,int y)
    {
        if(x%y==0) return y;

        else return findGcd(y,x%y);
    }

    public ListNode insertGreatestCommonDivisors(ListNode head) {

        if(head==null) return null;

        ListNode ptr1=head;
        ListNode ptr2=head.next;
        ListNode res=ptr1;

        while(ptr2!=null)
        {
            int x=Math.max(ptr1.val,ptr2.val);

            int y=Math.min(ptr1.val,ptr2.val);

            int gcd=findGcd(x,y);

            ListNode n=new ListNode(gcd);

            ptr1.next=n;

            n.next=ptr2;

            ptr1=ptr1.next.next;
            ptr2=ptr2.next;
        }

        return res;
        
    }
}
