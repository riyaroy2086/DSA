/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteMiddle(struct ListNode* head){
    if (head -> next == NULL)
        return NULL;
    struct ListNode *p1=head, *p2=head;
    int count = 0;
    
    while (p1 != NULL) {
        count++;
        p1= p1->next;
    }
    int x=count/2;
    for(int i=0;i<x-1;i++)
        p2=p2->next;
    p2 -> next = p2 -> next -> next;
    return head;
    
}
