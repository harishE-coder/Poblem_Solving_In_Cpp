# Remove-Linked-List-Elements

A C++ program to remove all nodes with a specific value from a linked list.

-----

## Problem

Given the `head` of a linked list and an integer `val`, remove all the nodes of the linked list that have `Node.val == val`, and return the *new head*.

-----

## Example

**Input:** `head = [1,2,6,3,4,5,6]`, `val = 6`

**Explanation:**
The original list is `1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6`. After removing all nodes with the value `6`, the list becomes `1 -> 2 -> 3 -> 4 -> 5`.

**Output:** `[1,2,3,4,5]`

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
    ListNode* removeElements(ListNode* head, int val) {
        // Create a dummy node to handle cases where the head needs to be removed.
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = dummy;

        while (prev->next != nullptr) {
            if (prev->next->val == val) {
                ListNode* toDelete = prev->next;
                // Bypass the node to be deleted
                prev->next = prev->next->next;
                delete toDelete; // Free memory
            } else {
                // Move to the next node
                prev = prev->next;
            }
        }

        ListNode* newHead = dummy->next;
        delete dummy; // Clean up the dummy node
        return newHead;
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
    
    // Create list: 1->2->6->3->4->5->6
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(6, 
                    new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6)))))));
    
    int val_to_remove = 6;

    std::cout << "Original List: ";
    printList(head);

    ListNode* newHead = sol.removeElements(head, val_to_remove);
    
    std::cout << "List after removing " << val_to_remove << ": ";
    printList(newHead); // Output: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr

    return 0;
}
```

-----

## Complexity

  - **Time:** $O(n)$, where `n` is the number of nodes in the linked list. We traverse the list exactly once.
  - **Space:** $O(1)$. We use a constant amount of extra space for the `dummy` and `prev` pointers.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o remove_elements main.cpp`
  - **Run:** `./remove_elements`

-----

## Notes

  - The use of a **dummy node** is a common and powerful technique in linked list problems. It simplifies the logic by ensuring that every node to be deleted (including the original head) has a valid preceding node (`prev`).
  - The `prev` pointer always points to the node *before* the one we are currently examining. This allows us to easily modify the `next` pointer of the preceding node to "bypass" and remove the current node.
  - It's crucial to manage memory properly by `delete`ing the nodes that are removed to prevent memory leaks.
