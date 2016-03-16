class Solution {
    public:
	int sumNumbers (TreeNode* root) {
	    if (!root) return 0;
	    return sumNumbers (0, root);
	}
	int sumNumbers (int prefix, TreeNode* root) {
	    prefix = prefix*10 + root->val;
	    int res = 0;
	    if (root->left) res += sumNumbers(prefix, root->left);
	    if (root->right) res += sumNumbers(prefix, root->right);
	    if (!root->left && !root->right) return prefix;
	    return res;
	}
};
