/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Recursive method
        // edge case
        if(head == NULL)
            return head;
        
        node* prev = NULL;
        node* curr = head;
        node* temp = NULL;
        
        int cnt=1;
        
        while(curr !=NULL && cnt <=k){
            temp = curr-> next; // otherwise will lose track of the rest of the LL
            curr-> next = prev;
            prev= curr;
            curr = temp;
           
            cnt++;
        }
        
        // reverse
        if(curr != NULL){
           // Node* n = head-> next;
            head-> next = reverse(curr,k);
        
        }
        return prev;
    }
};