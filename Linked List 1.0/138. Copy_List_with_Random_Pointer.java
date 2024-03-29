//https://leetcode.com/problems/copy-list-with-random-pointer/

/**
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value 
set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes 
in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers 
in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and
y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:
val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.

Your code will only be given the head of the original linked list.

 Example 1:

Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]


Example 2:

Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]

Example 3:

Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
*/

//---------------------------------------------------------------code here--------------------------------------------------------------------------------//

/*
/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {

        //----------------------------------------------------------optimised approach-------------------------------------------------------------------//
        
        if(head==null) return head;

        Node curr=head;

        while(curr!=null)
        {
            Node temp=curr.next;

            curr.next=new Node(curr.val);

            curr.next.next=temp;

            curr=temp;
        }

        curr=head;

        while(curr!=null)
        {
            if(curr.next!=null)
                curr.next.random=(curr.random!=null)?curr.random.next:null;
            curr=curr.next.next;
        }

        Node list=head;
        Node cp=head.next;
        Node ptr=cp;

        while(list!=null)
        {
            list.next=list.next.next;
            if(cp.next==null) break;
            cp.next=cp.next.next;
            list=list.next;
            cp=cp.next;
            
        }


        return ptr;

        //--------------------------------------------------------------brute force approach-------------------------------------------------------------//

        // HashMap<Node,Node> map=new HashMap<>();

        // Node curr=head;

        // while(curr!=null)
        // {
            
        //     Node newNode=new Node(curr.val);

        //     map.put(curr,newNode);

        //     curr=curr.next;
        // }

        // Node ptr=head;

        // while(ptr!=null)
        // {
        //     map.get(ptr).next=map.get(ptr.next);  //we can't directly use ptr.next as it would link it to the original list
        //     map.get(ptr).random=map.get(ptr.random);

        //     ptr=ptr.next;
        // }
        
        // return map.get(head);
    }
}
