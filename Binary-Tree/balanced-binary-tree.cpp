#include <vector>
#include <cmath>
#include <algorithm>

/**
 * Determines whether a binary tree is height-balanced using Depth First Search (DFS).
 * The recursive function computes the height of each subtree while simultaneously
 * checking whether that subtree is balanced. For every node, we calculate the
 * heights of its left and right subtrees. If their height difference is greater
 * than one, we know the tree is no longer balanced, so we update the shared
 * `balanced` flag to false. After checking the current node, we return its height
 * (1 + the taller subtree) so its parent can perform the same comparison.
 * Time Complexity: O(n)
 * Space Complexity: O(h), where h is the height of the tree.
 */

class Solution {
  public:
    bool isBalanced(TreeNode* root) {
      std::vector<bool> balanced = {true};
      dfs(root, balanced);
      return balanced[0];
    }

  private:
    int dfs(TreeNode* root, std::vector<bool>& balanced) {
      if (root == nullptr) {
        return 0;
      }
      int left = dfs(root->left, balanced);
      int right = dfs(root->right, balanced);
      if (std::abs(left - right) > 1) {
        balanced[0] = false;
      }
      return 1 + std::max(left, right);
    }
};
