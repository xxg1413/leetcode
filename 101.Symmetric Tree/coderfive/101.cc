class Solution {
public:
    bool isSymmetric(TreeNode* root) {
	TreeNode* left, *right;
	vector<TreeNode*> v;
	if (!root) return true;
	v.push_back(root->left);
	v.push_back(root->right);
	while (v.size() != 0) {
	    right = v.back();
	    v.pop_back();
	    left = v.back();
	    v.pop_back();
	    if (!left && !right) continue;
	    if (!left || !right) return false;
	    if (left->val != right->val) return false;
	    v.push_back(left->left);
	    v.push_back(right->right);
	    v.push_back(left->right);
	    v.push_back(right->left);
	}
	return true;
    }
};
