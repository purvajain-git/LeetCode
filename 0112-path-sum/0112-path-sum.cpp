class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;

        // Check if current node is a leaf
        if (root->left == nullptr && root->right == nullptr)
            return targetSum == root->val;

        // Subtract current node value and explore children
        int remaining = targetSum - root->val;

        return hasPathSum(root->left, remaining) ||
               hasPathSum(root->right, remaining);
    }
};