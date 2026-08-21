// Copyright (c) 2026 Christian Hinkle.

#include <ListNode.h>

class Solution
{
public:
    static ListNode* reverseList(ListNode* head)
    {
        ListNode* current = head;
        ListNode* previous{};

        while (current)
        {
            ListNode* next = current->next;

            current->next = previous;

            previous = current;
            current = next;
        }

        return previous;
    }
};
