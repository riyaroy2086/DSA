/* Node reverseList(Node h)
    {
        Node current=h;
        
        
        Node prev=null;
        Node next=null;
        
        while(current!=null)
        {
            next=current.next;
            current.next=prev;
            prev=current;
            current=next;
        }
        return prev;
    } */
    
    //Function to check whether the list is palindrome.
    boolean isPalindrome(Node head) 
    {
        //Your code here
        
      /*  Node s=head;
        Node f=head;
        
        while(f.next!=null && f.next.next!=null)
        {
            s=s.next;
            f=f.next.next;
        }
        
        
        Node n=head;
        Node rev=reverseList(s);
        
        while(rev!=null)
        {
            if(n.data != rev.data)
            {
                return false;
            }
            n=n.next;
            rev=rev.next;
        }
        return true; */
        
        
        // The code above failed some test cases so implemented this approach
        
        Node current=head;
        double n=0.0,rev=0.0;
        int c=0;
        while(current!=null)
        {
            n=(n*10)+current.data;
            rev=current.data*Math.pow(10,c++)+(double)rev;
            current=current.next;
        }
        if(n==rev)
        {
            return true;
        }
        return false;
        
    }
