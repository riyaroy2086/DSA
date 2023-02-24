ListNode *a=(struct ListNode *)malloc(sizeof(struct ListNode));
ListNode *head=a;

int carry = 0;
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        if (l1 != NULL) {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            sum += l2->data;
            l2 = l2->next;
        }
        int digit = sum % 10;
        carry = sum / 10;
    }
return a->next;
      
