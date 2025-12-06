# 94 Binary-Tree-Inorder-Traversal

A C++ program to perform an inorder traversal of a binary tree using an iterative approach (stack).

-----

## 📊 Difficulty Level

**Easy**

## 🔗 Problem Link

[LeetCode 94: Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/)

## 🏷️ Topic Tags

  - Stack
  - Tree
  - Depth-First Search
  - Binary Tree

-----

## Problem

Given the `root` of a binary tree, return the *inorder traversal* of its nodes' values.

In an **Inorder Traversal**, the nodes are visited in the following order:

1.  Left Subtree
2.  Root Node
3.  Right Subtree

[Image of inorder traversal binary tree]

-----

## Example

**Input:** `root = [1, null, 2, 3]`

**Structure:**

```
  1
   \
    2
   /
  3
```

**Explanation:**

1.  Traverse Left of 1 (null).
2.  Visit Root (1).
3.  Traverse Right of 1 (subtree rooted at 2).
    a. Traverse Left of 2 (3).
    b. Visit Root (2).
    c. Traverse Right of 2 (null).

**Output:** `[1, 3, 2]`

-----

## Code

```cpp
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* current = root;

        while (current != nullptr || !st.empty()) {
            // Step 1: Reach the leftmost node of the current subtree
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }

            // Step 2: Current is null, so pop the top node (which is the parent)
            current = st.top();
            st.pop();
            
            // Step 3: Add the node value to result
            result.push_back(current->val);

            // Step 4: Move to the right subtree
            current = current->right;
        }

        return result;
    }
};

// Example main to demonstrate usage
int main() {
    Solution sol;
    
    // Constructing the tree: [1, null, 2, 3]
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> result = sol.inorderTraversal(root);

    cout << "Inorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl; // Output: 1 3 2

    // Clean up memory (simple delete for this example)
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
```

-----

## Complexity

  - **Time:** $O(n)$, where `n` is the number of nodes in the tree. We visit every node exactly once.
  - **Space:** $O(h)$, where `h` is the height of the tree. This space is used by the stack. In the worst case (skewed tree), $h = n$. In the best case (balanced tree), $h = \log n$.

-----

## Build & Run

  - **Compile:** `g++ -std=c++17 -O2 -o inorder_traversal main.cpp`
  - **Run:** `./inorder_traversal`

-----

## Notes

  - **Iterative vs. Recursive:** The recursive solution is often simpler to write (`inorder(root->left); print; inorder(root->right);`), but the iterative solution using an explicit stack is safer against stack overflow errors for very deep trees.
  - The algorithm simulates the call stack of the recursive approach. We "pause" at each node, dive as deep left as possible, process the node, and then dive right.
