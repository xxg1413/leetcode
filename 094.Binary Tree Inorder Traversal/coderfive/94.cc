/*
 * this one is easy, so I don't want to make it a standalone program.
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
	    vector<int> v;
	    inorder(v, root);
	    return v;
    }
    // manual tail-recursion
    void inorder (vector<int>& v, TreeNode* root) {
begin:
	    if (!root) return;
	    inorder (v, root->left);
	    v.push_back(root->val);
	    root = root->right;
	    goto begin;
    }
};
