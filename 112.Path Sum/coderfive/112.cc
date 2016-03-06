class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
	if (!root) return false;
	sum -= root->val;
	if (root->left && hasPathSum(root->left, sum)) return true;
	if (root->right && hasPathSum(root->right, sum)) return true;
	if (!root->left && !root->right && sum == 0) return true;
	return false;
    }
};
