/**
 * Finds the diameter of a binary tree using Depth-First Search (DFS).
 * The diameter is the length (number of edges) of the longest path
 * between any two nodes in the tree. This path does not have to pass
 * through the root.
 * DFS returns the height of each subtree:
 *   - Height = 1 + max(left subtree height, right subtree height)
 * While computing heights, each node is treated as a potential "middle"
 * of the longest path. The longest path through that node is:
 *      left height + right height
 * If this value is larger than the current maximum diameter, we update it.
 * Time Complexity: O(n)
 * - Every node is visited exactly once.
 * Space Complexity: O(h)
 * - h is the height of the tree due to the recursion stack.
 * - Worst case: O(n) for a skewed tree.
 * - Best/average balanced tree: O(log n).
 */

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
private:
    int dfs(TreeNode* root, int& res) {
        if (!root) {
            return 0;
        }
        int left = dfs(root->left, res);
        int right = dfs(root->right, res);
        res = max(res, left + right);
        return 1 + max(left, right);
    }
};
