/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL|| left == right)
            return head;
        
        ListNode* d = new ListNode(-1);
        d->next = head;

        ListNode* prev = d;
        ListNode* curr = head;
        ListNode* temp = NULL;

        int i=1;
        for(;i<left;i++)
        {   
            prev = prev->next;
            curr = curr-> next;
        }

        ListNode *rev_dummy = prev;
        ListNode *rev_tail = curr;

        for(;i<=right;i++)
        {
            temp = curr-> next;
            curr-> next = prev;
            prev = curr;
            curr = temp;
        }
        rev_dummy-> next = prev;
        rev_tail-> next = curr;

        return d-> next;
    }
    
};
