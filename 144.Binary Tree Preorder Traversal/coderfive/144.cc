class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
	vector<int> res;
	TreeNode* left;

	while (root) {
	    left = root->left;
	    if (!left) {
		res.push_back(root->val);
		root = root->right;
		continue;
	    }
	    while (left->right && left->right != root) {
		left = left->right;
	    }
	    if (left->right) {
		left->right = NULL;
		root = root->right;
	    }
	    else {
		left->right = root;
		res.push_back(root->val);
		if (root->left)
		    root = root->left;
		else
		    root = root->right;
	    }
	}
	return res;
    }
};
