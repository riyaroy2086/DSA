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

TC -> O(N)
SC-> O(1)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *d = new ListNode();
        ListNode *head = d;
        int carry =0;
        while(l1|| l2||carry)
        {
            if(l1!=NULL)
            {
                carry+=l1->val;
                l1= l1->next;
            }
            if(l2!=NULL)
            {
                carry+=l2->val;
                l2=l2->next;
            }
            head->next = new ListNode(carry%10);
            carry/=10;
            head=head->next;
        }
        return d->next;
    }
};