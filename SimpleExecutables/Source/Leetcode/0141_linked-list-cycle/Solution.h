// Copyright (c) 2026 Christian Hinkle.

#include <ListNode.h>
#include <cassert>

/**
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
class Solution
{
public:
    static bool hasCycle(const ListNode *head)
    {
        // A simple case handled for the sake of a null check.
        if (!head)
        {
            return false;
        }

        // Have two traversers going at different speeds and detect when/if they meet. It's important that their
        // differing traversal speeds allow this to happen. E.g., speeds of two-step and four-step would not meet in all cases.
        const ListNode* traverser = head;
        const ListNode* traverserTwoStep = head->next;
        while (traverserTwoStep) // Note: If a cycle is present, then this loop condition will never fail. A break in the loop body must be encountered.
        {
            // Logically, our one-step traverser must be valid since our two-step one is.
            assert(traverser);

            if (traverserTwoStep == traverser)
            {
                // Cycle encountered.
                return true;
            }

            traverser = traverser->next;
            traverserTwoStep = traverserTwoStep->next ? traverserTwoStep->next->next : nullptr;
        }

        return false;
    }
};
