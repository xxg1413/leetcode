#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
    struct val_pair {
        int v1, v2, sum;
        val_pair() {}
        bool operator < (const val_pair& rhs) const {
            return sum < rhs.sum;
//            || (sum == rhs.sum && v1 < rhs.v1)
//                || (sum == rhs.sum && v1 == rhs.v1 && v2 < rhs.v2);
        }
        val_pair (int v1, int v2, int sum) {
            this->v1 = v1;
            this->v2 = v2;
            this->sum = sum;
        }
//        val_pair& operator = (const val_pair& vp) {
//            this->v1 = vp.v1;
//            this->v2 = vp.v2;
//            this->sum = sum;
//            if (this->v1 > this->v2) swap (this->v1, this->v2);
//            return *this;
//        }
    };
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            vector<vector<int>> res;
            if (nums.size() < 4) return res;

            vector<val_pair> v;
            v.resize (nums.size()*(nums.size()-1)/2);
            for (int i = 0, idx = 0; i < nums.size(); i++)
                for (int j = i+1; j < nums.size(); j++, idx++)
                    v[idx] = val_pair (i, j, nums[i]+nums[j]);
            sort (v.begin(), v.end());
            int start = 0, end = v.size()-1;
            int se;
            while (start < end) {
                while (start < end && v[start].sum + v[end].sum > target) end--;
                se = end;
                while (start < end && v[start].sum + v[end].sum == target) {
                    if (v[start].v1 != v[end].v1 && v[start].v1 != v[end].v2 
                            && v[start].v2 != v[end].v1 && v[start].v2 != v[end].v2) {
                        res.push_back (vector<int> {nums[v[start].v1], nums[v[start].v2], 
                                nums[v[end].v1], nums[v[end].v2]});
                        sort (res.back().begin(), res.back().end());
                    }
                    end--;
                }
                start++;
                if (start < se && v[start].sum + v[se].sum == target) end = se;
            }
            sort (res.begin(), res.end());
            res.resize (unique (res.begin(), res.end())-res.begin());
            return res;
        }
};

/*
 * input: vector<int> int ## vector<vector<int>>
 * vector<T>: {}
 *             | {T [, T]*}
 */

template <typename T>
istream& operator >> (istream& in, vector<T>& v) {
    T val;
    while (!in.eof() && isspace(in.peek())) in.get();
    if (in.peek() == '{') in.get();
    else return in;

    v.clear();

    while (true) {
        while (isspace(in.peek())) in.get();
        if (in.peek() == '}') {
            in.get();
            return in;
        }
        else if (in.peek() == ',') in.get();
        in >> val;
        v.push_back(val);
    }

    return in;
}

template <typename T>
ostream& operator << (ostream& out, vector<T>& v) {
    out << "{";
    if (v.size() != 0)
        out << v[0];
    for (int i = 1; i < v.size(); i++)
        out << ", " << v[i];
    out << "}";

    return out;
}

int main() {
    int err = 0, target;
    string buf;
    vector<vector<int>> res, ret;
    vector<int> vi;

    while (true) {
        cin >> vi;
        if (cin.eof()) break;
        cin >> target >> buf >> res;
        ret = Solution().fourSum(vi, target);

        sort(ret.begin(), ret.end());
        sort(res.begin(), res.end());
        if (ret != res) {
            err = 1;
            cout << "input: " << vi << " " << target << endl
                 << "ret: " << ret << endl
                 << "expected: " << res << endl << endl;
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
