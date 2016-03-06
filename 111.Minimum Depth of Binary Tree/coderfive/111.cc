class Solution {
public:
    int minDepth(TreeNode* root) {
	if (!root) return 0;
	int left = minDepth(root->left);
	int right = minDepth(root->right);
	if (left == 0 || right == 0) return 1+left+right;
	return 1 + std::min(left, right);
    }
};
