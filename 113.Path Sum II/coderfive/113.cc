class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
	vector<vector<int>> res;
	vector<int> v;
	helper(root, res, v, sum);
	return res;
    }
    void helper (TreeNode* root, vector<vector<int>>& res, vector<int>& path, int sum) {
	if (!root) return;
	path.push_back(root->val);
	sum -= root->val;
	if (!root->left && !root->right && sum == 0)
	    res.push_back(path);
	helper(root->left, res, path, sum);
	helper(root->right, res, path, sum);

	path.pop_back();
    }
};
