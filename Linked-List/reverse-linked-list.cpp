/*
 * We reverse the linked list by changing the direction of each node's `next` pointer.
 * We use three pointers:
 *
 * - prev: Points to the previous node in the reversed list. It starts as nullptr
 *   because the new tail of the list should point to nothing.
 *
 * - curr: Points to the current node we are processing. It starts at the head
 *   and moves through the list one node at a time.
 *
 * - temp: Temporarily stores curr->next before we change the pointer. Without
 *   temp, we would lose access to the rest of the list after reversing the link.
 *
 * Process:
 * 1. Save the next node in temp.
 * 2. Reverse the current node's pointer so it points to prev.
 * 3. Move prev forward to the current node.
 * 4. Move curr forward using temp.
 *
 * Once curr becomes nullptr, we have processed every node. At that point,
 * prev points to the new head of the reversed linked list, so we return prev.
 */

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr) {
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}
