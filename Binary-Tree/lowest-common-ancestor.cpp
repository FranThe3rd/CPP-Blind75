
/*
This solution finds the Lowest Common Ancestor (LCA) in a Binary Search Tree (BST) by taking advantage
of the BST property that all values in the left subtree are smaller than the current node
and all values in the right subtree are larger. Starting at the root, we compare
the values of p and q with the current node. If both values are greater than the current node
, we continue searching in the right subtree. If both values are smaller, we continue searching
in the left subtree. Otherwise, the current node is where the paths to p and q diverge
(or one of the nodes is the current node), making it the lowest common ancestor. Since only
one path from the root is traversed, the algorithm runs in O(h) time, where h is the height of the tree, and
uses O(1) extra space because it is implemented iteratively.
*/

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* curr = root;

    while (curr != nullptr) {
        if (p->val > curr->val && q->val > curr->val) {
            curr = curr->right;
        } else if (p->val < curr->val && q->val < curr->val) {
            curr = curr->left;
        } else {
            return curr;
        }
    }

    return nullptr;
}
