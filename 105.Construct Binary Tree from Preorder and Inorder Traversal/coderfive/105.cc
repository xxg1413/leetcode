class Solution {
public:
    using vii = vector<int>::iterator;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	return buildTree (preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
    TreeNode* buildTree(vii pb, vii pe, vii ib, vii ie) {
	TreeNode* res = NULL;
	if (pb == pe) return res;
	res = new TreeNode(*pb);
	int left_size = std::find (ib, ie, *pb) - ib;
	res->left = buildTree (pb+1, pb+1+left_size, ib, ib+left_size);
	res->right = buildTree (pb+1+left_size, pe, ib+left_size+1, ie);
	return res;
    }
};
