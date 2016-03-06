class Solution {
public:
    int maxPathSum(TreeNode* root) {
	if (!root) return 0;
	int max, max_self;
	max_ps(root, max, max_self);
	return std::max(max, max_self);
    }
    void max_ps (TreeNode* root, int& max, int& max_self) {
	int leftm = 0, rightm = 0, leftms = 0, rightms = 0;
	max = max_self = root->val;
	if (root->left) {
	    max_ps (root->left, leftm, leftms);
	    max_self = std::max(max_self, root->val + leftms);
	    max = std::max(max, max_self);
	    max = std::max(max, leftm);
	}

	if (root->right) {
	    max_ps (root->right, rightm, rightms);
	    max_self = std::max(max_self, root->val + rightms);
	    max = std::max(max, max_self);
	    max = std::max(max, rightm);
	    if (root->left) {
		max = std::max(max, root->val+leftms+rightms);
	    }
	}
    }
};
