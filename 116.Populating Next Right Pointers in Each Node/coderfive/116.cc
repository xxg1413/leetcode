class Solution {
public:
    void connect(TreeLinkNode *root) {
	if (!root) return;
	if (!root->left) return;
	TreeLinkNode* left = root->left, *right = root->right;
	while (left) {
	    left->next = right;
	    left = left->right;
	    right = right->left;
	}
	connect(root->left);
	connect(root->right);
    }
};
