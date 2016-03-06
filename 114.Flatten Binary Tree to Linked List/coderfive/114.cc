class Solution {
public:
    void flatten(TreeNode* root) {
	if (!root) return;
	helper(root);
    }
    TreeNode* helper (TreeNode* root) {
	TreeNode* cur = root, *right = root->right;
	if (root->left) {
	    root->right = root->left;
	    cur = helper(root->left);
	    root->left = NULL;
	}
	if (right) {
	    cur->right = right;
	    cur = helper(right);
	}
	return cur;
    }
};
