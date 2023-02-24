/*
class Node
{
    int data;
    Node next;
}
*/

class Solution
{
    //Function to remove a loop in the linked list.
    public static void removeLoop(Node head){
        // code here
        // remove the loop without losing any nodes
        
        boolean x=false;
        
        Node f=head;
        Node s=head;
        while(f!=null && f.next!=null)
        {
            s=s.next;
            f=f.next.next;
            if(s==f)
            {
                x=true;
                break;
                
            }
            
        }
        if(x)  //if the loop is found
        {
            s=head;    //reset the slow pointer to head
            
            while(s!=f)   //finding the starting of the loop
            {
                s=s.next;
                f=f.next;   
            }  
            
            Node n=s;  
        
            while(n.next!=s)   //removing the loop
            {
                n=n.next;
            }
            n.next=null;
        }
        
    }
}
