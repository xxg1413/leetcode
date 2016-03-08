#include <map>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
    public:
	UndirectedGraphNode* cloneGraph (UndirectedGraphNode* node) {
	    if (!node) return node;
	    map<int, UndirectedGraphNode*> mp;
	    vector<pair<UndirectedGraphNode*, UndirectedGraphNode*>> vp;
	    vp.push_back(make_pair(new UndirectedGraphNode(node->label), node));
	    mp[node->label] = vp.back().first;
	    while (!vp.empty()) {
		auto p = vp.back();
		vp.pop_back();
		for (auto it = p.second->neighbors.begin(); it != p.second->neighbors.end(); it++) {
		    auto neib = *it;
		    auto nnd = mp.find(neib->label);
		    if (nnd != mp.end())
			p.first->neighbors.push_back(nnd->second);
		    else {
			auto new_node = new UndirectedGraphNode(neib->label);
			p.first->neighbors.push_back(new_node);
			mp[neib->label] = new_node;
			vp.push_back(make_pair(new_node, neib)); 
		    }
		}
	    }

	    return mp[node->label];
	}
};

int main() {
    Solution().cloneGraph(new UndirectedGraphNode(-1));

    return 0;
}

