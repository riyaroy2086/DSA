//https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

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
    public int pairSum(ListNode head) {

        Stack<ListNode> nodes=new Stack<>();

        ListNode curr=head;

        while(curr!=null)
        {
            nodes.push(curr);               //storing the linkedlist nodes in the stack
            curr=curr.next;
        }

        int initialHalfSize=nodes.size()/2;  //to get to the exact middle of the initial stack

        int max=0;

        while(nodes.size()>initialHalfSize)  //checking if the stack has already been reduced to half of its initial elements
        {
            max=Math.max(max,nodes.pop().val+head.val);
            head=head.next;
        }

        return max;
        
    }
}
