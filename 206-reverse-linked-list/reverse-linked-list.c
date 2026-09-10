/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;

    while (curr != NULL) {

        // Store next node
        next = curr -> next;

        // Reverse the link
        curr -> next = prev;

        // Move prev and curr forward
        prev = curr;
        curr = next;
        
    }
    return prev;
}