// Copyright (c) 2026 Christian Hinkle.

#include <ListNode.h>

/**
 * Note: Recursive solution, which is interesting and unusual.
 */
class Solution
{
public:
    static ListNode* reverseList(ListNode* head)
    {
        if (!head)
        {
            return nullptr;
        }

        return &reverseListImpl(*head);
    }

private:
    // Note: The only purpose of the return value is to store and keep track of the tail node of the list throughout all the recursive calls (the tail will become the reversed head).
    static ListNode& reverseListImpl(ListNode& head)
    {
        // Base case: If there is no next node, then we are the tail.
        if (!head.next)
        {
            return head;
        }

        // Recurse as deep as we can, all the way to the tail.
        ListNode& tail = reverseListImpl(*head.next);
        // Now, the recursive calls are returning, and we are effectively traversing backward over the list.

        // Switch direction of this connection, if there is one.
        if (head.next)
        {
            head.next->next = &head;
        }

        // Now this node needs to point to the previous one. We set it to null by default, and let the outer recursive call switch the direction for us.
        head.next = nullptr;

        return tail;
    }
};
