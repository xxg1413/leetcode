class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
	return toBST (nums, 0, nums.size());
    }
    TreeNode* toBST (const vector<int>& v, int b, int e) {
	if (b == e) return NULL;
	int mid = b + (e-b)/2;
	TreeNode* node = new TreeNode(v[mid]);
	node->left = toBST(v, b, mid);
	node->right = toBST(v, mid+1, e);
	return node;
    }
};
