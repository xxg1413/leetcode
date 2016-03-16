class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        rightSideView(root, res, 1);

        return res;
    }
    void rightSideView (TreeNode* root, vector<int>& res, int depth) {
        if (depth > res.size()) res.push_back(root->val);
        if (root->right) rightSideView (root->right, res, depth+1);
        if (root->left) rightSideView (root->left, res, depth+1);
    }
};
