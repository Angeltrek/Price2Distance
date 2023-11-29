/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  long long pathSum(TreeNode *root, int targetSum) {
    long long paths = 0;
    if (!pathSumHelper(root, targetSum, paths)) {
      return numeric_limits<long long>::min();
    }
    return paths;
  }

  bool pathSumHelper(TreeNode *root, int targetSum, long long &paths) {
    if (!root)
      return true;

    long long currentSum = 0;
    if (!pathSumFromNode(root, targetSum, currentSum, paths)) {
      return false;
    }

    if (!pathSumHelper(root->left, targetSum, paths) ||
        !pathSumHelper(root->right, targetSum, paths)) {
      return false;
    }

    return true;
  }

  bool pathSumFromNode(TreeNode *node, int targetSum, long long currentSum,
                       long long &paths) {
    if (!node)
      return true;

    currentSum += node->val;

    if (currentSum == targetSum) {
      paths += 1;
    }

    if (currentSum > numeric_limits<long long>::max() ||
        currentSum < numeric_limits<long long>::min()) {
      return false;
    }

    return pathSumFromNode(node->left, targetSum, currentSum, paths) &&
           pathSumFromNode(node->right, targetSum, currentSum, paths);
  }
};