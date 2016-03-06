class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
	vector<vector<int>> res;
	vector<TreeNode*> v, v2, *p = &v, *p2 = &v2;
	if (!root) return res;
	v.push_back(root);
	while (p->size() != 0) {
	    vector<int> vi;
	    for (int i = 0; i < p->size(); i++) {
		vi.push_back((*p)[i]->val);
		if ((*p)[i]->left) p2->push_back((*p)[i]->left);
		if ((*p)[i]->right) p2->push_back((*p)[i]->right);
	    }
	    res.push_back(std::move(vi));
	    std::swap (p, p2);
	    p2->clear();
	}
	std::reverse(res.begin(), res.end());

	return res;
    }
};
