// Copyright (c) 2026 Christian Hinkle.

#include <cstddef>

/**
 * Copied from leetcode's "Definition for singly-linked list".
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
