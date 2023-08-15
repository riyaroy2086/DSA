//https://leetcode.com/problems/partition-list/

/*
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example 1:

Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]

*/

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
    public ListNode partition(ListNode head, int x) {

        ListNode s=new ListNode(0); //initialize the value with 0 to avoid uncertain errors
        ListNode g=new ListNode(0);
        ListNode l1=s;
        ListNode l2=g;

        ListNode curr=head;

        while(curr!=null)
        {
            if(curr.val<x)
            {
                s.next=new ListNode(curr.val);
                s=s.next;
            }
                

            else
            {
                g.next=new ListNode(curr.val);
                g=g.next;
            }
                
            curr=curr.next;

        }

        s.next=l2.next;

        return l1.next;
        
    }
}
