
# 112. Path Sum 
## Describe
Given the root of a binary tree and an integer targetSum, return **true** if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
A leaf is a node with no children.

### Example
  ```
  Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
  Output: true
  Explanation: The root-to-leaf path with the target sum is shown.
  ```
## Idea
* DFS from root (recursive)

# 113. Path Sum II
## Describe
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as **a list of the node values**, not node references.
A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

### Example

  ```
  Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
  Output: [[5,4,11,2],[5,8,4,5]]
  Explanation: There are two paths whose sum equals targetSum:
  5 + 4 + 11 + 2 = 22
  5 + 8 + 4 + 5 = 22
  ```
## Idea
* Similar with 112, DFS from root (recursive)
* using vector to record path
  * push_back(cur_node)
  * if left subtree and right subtree is ending, pop_back()
