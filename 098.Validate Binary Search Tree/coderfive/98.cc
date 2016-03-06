class Solution {
public:
	bool is_valid (TreeNode* root, long long& min, long long& max) {
		if (!root) return true;
		long long local_min = root->val+1LL, local_max = root->val-1LL, a = 0;
		if (root->left) {
		       if (root->left->val >= root->val) return false;
		       if (!is_valid(root->left, min, local_max)) return false;
		}
		if (root->right) {
		       if (root->right->val <= root->val) return false;
		       if (!is_valid(root->right, local_min, max)) return false;
		}
		if (local_max >= root->val || local_min <= root->val) return false;
		if (min > root->val) min = root->val;
		if (max < root->val) max = root->val;
		return true;
	}
    bool isValidBST(TreeNode* root) {
	    long long a, b;
	    return is_valid (root, a, b);
    }
};
