// Copyright (c) 2026 Christian Hinkle.

#include <Solution.h>

int main()
{
    // Input: head = [1,2,3,4,5]
    // Output: [5,4,3,2,1]
    ListNode& head = *new ListNode{1};
    head.next = new ListNode{2};
    head.next->next = new ListNode{3};
    head.next->next->next = new ListNode{4};
    head.next->next->next->next = new ListNode{5};

    ListNode* headReversed = Solution::reverseList(&head);

    return 0;
}
