class Solution {
public:
    bool isBalanced(TreeNode* root) {
	int a = 0;
	return is_b (root, a);
    }
    bool is_b (TreeNode* root, int& depth) {
	if (!root) return true;
	int a = 0, b = 0;
	if (!is_b(root->left, a)) return false;
       	if (!is_b(root->right, b)) return false;
	if (a < b) std::swap(a, b);
	if (a-b > 1) return false;
	depth += a+1;
	return true;
    }
};
