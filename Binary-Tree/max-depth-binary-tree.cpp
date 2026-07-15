


/**
 * Solves the problem using Depth-First Search (DFS) with recursion.
 * Starting from the root, it recursively finds the maximum depth of
 * the left and right subtrees, takes the larger of the two, and adds
 * 1 for the current node. If a node is null, its depth is 0.
 */

int maxDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
