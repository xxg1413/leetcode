class Solution {
public:
    using vii = vector<int>::iterator;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
	return buildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
    TreeNode* buildTree(vii ib, vii ie, vii pb, vii pe) {
	if (pb == pe) return NULL;
	int val = *(pe-1);
	TreeNode* res = new TreeNode(val);
	int left_size = std::find(ib, ie, val) - ib;
	res->left = buildTree(ib, ib+left_size, pb, pb+left_size);
	res->right = buildTree(ib+left_size+1, ie, pb+left_size, pe-1);
	return res;
    }
};
