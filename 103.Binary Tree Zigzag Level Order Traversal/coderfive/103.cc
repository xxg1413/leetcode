class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	vector<vector<int>> res;
	vector<TreeNode*> v, v2, *p = &v, *p2 = &v2;
	bool left2right = true;
	int start, stop, step;
	if (!root) return res;
	v.push_back(root);
	while (p->size() != 0) {
	    if (left2right) {
		start = 0;
		stop = p->size();
		step = 1;
	    }
	    else {
		start = p->size()-1;
		stop = -1;
		step = -1;
	    }
	    left2right = !left2right;
	    vector<TreeNode*>& nv = *p;
	    vector<TreeNode*>& nv2 = *p2;
	    res.push_back(vector<int>());
	    vector<int>& vi = res.back();
	    for (; start != stop; start += step) {
		vi.push_back(nv[start]->val);
	    }
	    for (int i = 0; i < p->size(); i++) {
		if (nv[i]->left)
		    nv2.push_back(nv[i]->left);
		if (nv[i]->right)
		    nv2.push_back(nv[i]->right);
	    }
	    swap (p, p2);
	    p2->clear();
	}

	return res;
    }
};
