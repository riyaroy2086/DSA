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

    public int findSize(ListNode h)
    {
        ListNode current=h;
        int s=0;
        while(current!=null)
        {
            s++;
            current=current.next;
        }
        return s;
    }

    public ListNode removeNthFromEnd(ListNode head, int n) {
       
        if(head==null || head.next==null) 
        {
            return null;

        }

        ListNode current=head;
        int size=findSize(head);

        if(size==n)
        {
            return head.next;
        }

        int r=size-n;

        int c=0;
        
        while(current!=null && current.next!=null)
        {
            c++;
            
            if(c==r)
            {
                current.next=current.next.next;
                break;
            }
            current=current.next;
        }
        return head;

    }
}
