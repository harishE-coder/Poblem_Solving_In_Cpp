# Merge-Two-Sorted-Lists

A C++ program to merge two sorted linked lists into one single sorted list.

-----

## Problem

You are given the heads of two sorted linked lists, `list1` and `list2`. Merge the two lists into one **sorted** list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

-----

## Example

**Input:** `list1 = [1, 2, 4]`, `list2 = [1, 3, 4]`

**Explanation:**
The algorithm iterates through both lists, picking the smaller node at each step to build the new list.

1.  Compare `1` and `1`. Take `1` from `list2`. New list: `1`.
2.  Compare `1` and `3`. Take `1` from `list1`. New list: `1 -> 1`.
3.  Compare `2` and `3`. Take `2` from `list1`. New list: `1 -> 1 -> 2`.
4.  Compare `4` and `3`. Take `3` from `list2`. New list: `1 -> 1 -> 2 -> 3`.
5.  Compare `4` and `4`. Take `4` from `list2`. New list: `1 -> 1 -> 2 -> 3 -> 4`.
6.  Attach the remainder of `list1` (`[4]`).

**Output:** `[1, 1, 2, 3, 4, 4]`

-----

## Code

```cpp
#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Dummy node to serve as the starting point of the merged list.
        ListNode dummy;
        ListNode* tail = &dummy;
        
        // Traverse both lists and append the smaller node to the tail.
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // Attach the remaining part of the non-empty list.
        tail->next = list1 ? list1 : list2;
        
        return dummy.next;
    }
};

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

// Example main to demonstrate usage
int main() {
    Solution sol;
    
    // Create list1: 1 -> 2 -> 4
    ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    
    // Create list2: 1 -> 3 -> 4
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    std::cout << "List 1: ";
    printList(l1);
    std::cout << "List 2: ";
    printList(l2);

    ListNode* mergedHead = sol.mergeTwoLists(l1, l2);
    
    std::cout << "Merged List: ";
    printList(mergedHead); // Output: 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> nullptr

    return 0;
}
```

-----

## Complexity

  - **Time:** $O(m + n)$, where `m` and `n` are the number of nodes in `list1` and `list2`, respectively. We must traverse each node in both lists once.
  - **Space:** $O(1)$. The algorithm restitches the existing nodes in place, using only a few extra pointers (`dummy`, `tail`). No new nodes are allocated.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o merge_lists main.cpp`
  - **Run:** `./merge_lists`

-----

## Notes

  - This solution uses a **dummy node** (`dummy`) to simplify the code. The `tail` pointer tracks the end of the newly formed list, starting from the dummy node. This avoids needing a separate check for the head of the merged list.
  - The final merged list is `dummy.next`.
  - After the `while` loop, one of the lists may still have remaining nodes. The line `tail->next = list1 ? list1 : list2;` efficiently appends the rest of the non-empty list to the end of the merged list.
