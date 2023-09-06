//https://leetcode.com/problems/split-linked-list-in-parts/

/**
Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a 
size greater than or equal to parts occurring later.

Return an array of the k parts.

Example 1:

Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].


Example 2:

Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.
*/


//---------------------------------------------------------------code here---------------------------------------------------------------------------------//


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
    public ListNode[] splitListToParts(ListNode head, int k) {

        ListNode curr=head;

        int length=0;

        while(curr!=null)
        {
            length++;
            curr=curr.next;
        }

        int r=length%k;

        ListNode arr[]=new ListNode[k];

        curr=head;
        ListNode prev=null;

        for(int i=0;i<k && curr!=null;i++)
        {
            arr[i]=curr;

            for(int j=0;j<(length/k)+((r>0)?1:0);j++)
            {
                prev=curr;
                curr=curr.next;
            }
            
            prev.next=null;

            if(r>0) r--;
        }

        return arr;
        
    }
}
