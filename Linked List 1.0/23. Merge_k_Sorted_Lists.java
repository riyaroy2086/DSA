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

    //Its the the most optimised solution possible
    //TC: O(nlog(k))
    //SC: O(1)

    public ListNode merge(ListNode l1,ListNode l2)
    {
        if(l1==null) return l2;
        if(l2==null) return l1;

        ListNode head=new ListNode(0);
        ListNode current=head;

        while(l1!=null && l2!=null)
        {
            if(l1.val<l2.val)
            {
                current.next=new ListNode(l1.val);
                l1=l1.next;
            }
            else
            {
                current.next=new ListNode(l2.val);
                l2=l2.next;
            }
            current=current.next;
        }

        while(l1!=null)
        {
            current.next=new ListNode(l1.val);
            l1=l1.next;
            current=current.next;
        }
        while(l2!=null)
        {
            current.next=new ListNode(l2.val);
            l2=l2.next;
            current=current.next;
        }

        return head.next;

    }

    public ListNode mergeKLists(ListNode[] lists) {

        if(lists==null || lists.length==0) return null;

        int interval=1;

        while(interval<lists.length)
        {
            for(int i=0;i+interval<lists.length;i=i+(interval*2))
            {
                lists[i]=merge(lists[i],lists[i+interval]);
            }
            interval*=2;
        }

        return lists[0];

    }

    //Brute force solution with TC: O(nlogn) and showing TLE

   /* ArrayList<Integer> arr=new ArrayList<Integer>();

    public void insert(ListNode n)
    {
        while(n!=null)
        {
            arr.add(n.val);
        }
    }

    public ListNode mergeKLists(ListNode[] lists) {

        for(ListNode i:lists)
        {
            insert(i);
        }

        Collections.sort(arr);
 
        ListNode head=new ListNode(arr.get(0));
        ListNode current=head;

        for(int i=1;i<arr.size();i++)
        {
            ListNode newNode=new ListNode(i);
            current.next=newNode;
            current=current.next;
        }
        return head;
        
    } */

}
