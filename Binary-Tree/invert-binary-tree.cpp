



/*
 * So to invert a binary tree, we use recursion and first check if the current
 * node is nullptr. If it is, we return because there is nothing left to invert.
 * Otherwise, we swap the node's left and right children using a temporary pointer.
 * After swapping, we recursively call the function on the new left and right
 * children so every node in the tree gets its children swapped. Once all recursive
 * calls finish, the entire tree has been inverted, and we return the original root.
 */



TreeNode* invertTree(TreeNode* root) {
  if (root == nullptr) {
    return nullptr;
  }

  TreeNode* tmp = root->left;
  root->left = root->right;
  root->right = tmp;

  invertTree(root->left);
  invertTree(root->right);

  return root;
}
