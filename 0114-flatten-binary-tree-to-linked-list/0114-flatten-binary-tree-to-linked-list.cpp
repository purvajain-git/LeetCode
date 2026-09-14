class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while (curr != NULL) {

            if (curr->left != NULL) {

                // Find the rightmost node of the left subtree
                TreeNode* prev = curr->left;
                while (prev->right != NULL) {
                    prev = prev->right;
                }

                // Connect original right subtree
                prev->right = curr->right;

                // Move left subtree to right
                curr->right = curr->left;
                curr->left = NULL;
            }

            // Move to next node
            curr = curr->right;
        }
    }
};