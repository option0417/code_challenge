tion for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head   = l1;
    int offset              = 0;
    
    while (l1->next && l2->next) {
        l1->val = l1->val + l2->val + offset; 
        offset  = l1->val / 10;
        l1->val = l1->val % 10;
        
        l1 = l1->next;
        l2 = l2->next;
    }
    
    l1->val = l1->val + l2->val + offset; 
    offset  = l1->val / 10;
    l1->val = l1->val % 10;
    
    if (l2->next) {
        l1->next = l2->next;
    }

    while (l1->next) {
        l1->next->val   += offset;
        offset          = l1->next->val / 10;
        l1->next->val   %= 10;
    
        l1 = l1->next;
    }    
    
    if (offset > 0) {
        struct ListNode* newNode    = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val                = offset;
        newNode->next               = NULL;
        l1->next = newNode;
    }
    
    return head;
}
