#include <vector>
#include <queue>

/*
 * Must implement the breadth first search algorithm, or use the level order traversal
 * So we start with a queue since its FIFO, the first thing we do is add the root node
 * to our queue. Then we iterate as long as the queue is not empty, at first it will be 
 * the root node, so the length of the the queue will be one. We make a level vector
 * We iterate the length of one, and the node that is in the queue will be popped 
 * but first it will be stored in a variable called node. We check if the node is not
 * null, if its not null, we add it to the level array, and push its children on the queue
 * Now the queue has its children so we can assume it has two childre, and now we iterate the
 * through the for loop of a length of 2 since there is 2 nodes (presumeably).
 *
 *
 *
 *
 * */


std::vector<std::vector<int>> levelOrder(TreeNode* root) {
  std::vector<std::vector<int>> result;
  std::queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    std::vector<int> level;
    for (int i = 0; i < q.size(); i++) {
      TreeNode* node = q.front();
      q.pop();
      if (node) {
        level.push_baclk(node->val);
        q.push(node->left);
        q.push(node->right);
      }
    }
    if (!level.empty()) {
      res.push_back(level);
    }

  }
  return res
}






