class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> res;
	vector<TreeNode*> v, v2, *p = &v, *p2 = &v2;
	if (!root) return res;
	v.push_back(root);
	while (p->size() != 0) {
	    res.push_back(vector<int>());
	    for (auto it = p->begin(); it != p->end(); it++) {
		    res.back().push_back((*it)->val);
		    if ((*it)->left)
			p2->push_back((*it)->left);
		    if ((*it)->right)
			p2->push_back((*it)->right);
	    }
	    swap(p, p2);
	    p2->clear();
	}

	return res;
    }
};
