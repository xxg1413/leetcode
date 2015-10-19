#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>> res; 
            vector<int> one_res;
            sort (candidates.begin(), candidates.end());
            candidates.resize (unique (candidates.begin(), candidates.end()) - candidates.begin());

            check_one (res, candidates, 0, one_res, target);

            return res;
        }

        void check_one (vector<vector<int>>& res, vector<int>& candidates,
                int idx, vector<int>& one_res, int target) {
            if (idx >= candidates.size()) return;
            if (candidates[idx] > target) return;
            int i;
            int size = one_res.size();
            for (i = 0; target >= i*candidates[idx]; i++) {
                if (target == i*candidates[idx])
                    res.push_back (one_res);
                else
                    check_one (res, candidates, idx+1, one_res, target-i*candidates[idx]);
                one_res.push_back(candidates[idx]);
            }
            one_res.resize(size);
        }
};

/*
 * input: vector<int> int ## vector<vector<int>>
 */

template<typename T>
istream& operator >> (istream& in, vector<T>& vi) {
    T val;
    vi.clear();
    while (!in.eof() && isspace(in.peek())) in.get();
    if (in.eof()) return in;
    in.get();

    while (true) {
        while (isspace(in.peek())) in.get();
        if (in.peek() == '}') {
            in.get();
            return in;
        }
        else if (in.peek() == ',') in.get();
        in >> val;
        vi.push_back(val);
    }

    return in;
}

template<typename T>
ostream& operator << (ostream& out, vector<T>& vi) {
    out << "{";
    if (vi.size() != 0)
        out << vi[0];
    for (int i = 1; i < vi.size(); i++)
        out << ", " << vi[i];
    out << "}";
    return out;
}


int main() {
    int err = 0;
    string buf;
    vector<vector<int>> expected, ret;
    vector<int> vi, saved_vi;
    int target;

    while (true) {
        cin >> vi;
        if (cin.eof()) break;
        cin >> target >> buf >> expected;
        saved_vi = vi;

        ret = Solution().combinationSum(vi, target);
        sort (expected.begin(), expected.end());
        sort (ret.begin(), ret.end());

        if (ret != expected) {
            err = 1;
            cout << "input: " << saved_vi << "  " << target << endl
                 << "ret: " << ret << endl
                 << "expected: " << expected << endl << endl;
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
