#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
    public:
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            vector<vector<int>> res;
            vector<int> one_res;

            sort (candidates.begin(), candidates.end());
            check_one (res, one_res, candidates, 0, target);

            return res;
        }

        void check_one (vector<vector<int>>& res, vector<int>& one_res,
                vector<int>& candidates, int idx, int target) {
            if (idx >= candidates.size()) return;
            if (target < candidates[idx]) return;

            one_res.push_back(candidates[idx]);
            if (target == candidates[idx])
                res.push_back(one_res);
            check_one (res, one_res, candidates, idx+1, target-candidates[idx]);
            one_res.pop_back();

            idx++;
            while (idx < candidates.size() && candidates[idx] == candidates[idx-1])
                idx++;
            check_one (res, one_res, candidates, idx, target);
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

        ret = Solution().combinationSum2(vi, target);
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
