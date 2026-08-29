// Copyright (c) 2026 Christian Hinkle.

#include <ListNode.h>
#include <cassert>

/**
 * Time complexity: O(n_1 + n_2)
 * Space complexity: O(1)
 */
class Solution
{
public:
    static ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* merged{};

        {
            ListNode* current1 = list1;
            ListNode* current2 = list2;

            ListNode* mergedTail{};
            while (ListNode* nextNode = chooseNextNode(current1, current2))
            {
                // Advance the current pointer of the list that was chosen.
                if (nextNode == current1)
                {
                    current1 = current1->next;
                }
                else
                {
                    assert(nextNode == current2);
                    current2 = current2->next;
                }

                // Note: At this point, the nextNode->next pointer is linking to one of the source lists, which is weird, but this will get
                // updated next iteration or it will naturally be null if we have reached the end of the lists anyway.

                // Append this node to the merged list.
                if (!merged)
                {
                    // First iteration case.
                    merged = nextNode;
                }
                else
                {
                    assert(mergedTail);
                    mergedTail->next = nextNode;
                }

                // Update the tail pointer.
                mergedTail = nextNode;
            }
        }

        return merged;
    }

private:
    static ListNode* chooseNextNode(ListNode* current1, ListNode* current2)
    {
        if (!current2)
        {
            return current1;
        }

        if (!current1)
        {
            return current2;
        }

        if (current1->val <= current2->val)
        {
            return current1;
        }
        else
        {
            return current2;
        }
    }
};
