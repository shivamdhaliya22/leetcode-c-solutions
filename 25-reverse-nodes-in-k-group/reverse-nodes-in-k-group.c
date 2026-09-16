/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {

    
      // Check whether at least k nodes are available
    struct ListNode* temp = head;
    
    for (int i = 0; i < k; i++) {
        if (temp == NULL)
            return head;
        temp = temp->next;
    }

    // Reverse first k nodes
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    
    for (int i = 0; i < k; i++) {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // head is now the last node of reversed group
    head->next = reverseKGroup(curr, k);

    // prev becomes the new head
    return prev;
}