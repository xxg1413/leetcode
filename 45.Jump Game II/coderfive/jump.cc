#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
#include <numeric>
using namespace std;

class Solution {
    public:
        int jump(vector<int>& nums) {
            if (nums.size() < 2) return 0;

            vector<int> idx;
            idx.push_back(0);
            idx.push_back(nums.size());
            for (int i = 1; idx[i] > 1; i++) {
                idx.push_back (idx[i]/2);
                if (idx[i] & 1)
                    idx.back()++;
            }
            std::partial_sum (idx.begin(), idx.end(), idx.begin());
            vector<int> seg_tree (idx.back(), std::numeric_limits<int>::max());
            update_tree (seg_tree, idx, nums.size()-1, 0);

            int val;
            for (int i = nums.size()-2; i >= 0; i--) {
                if (nums[i] == 0) continue;
                if (nums[i]+i >= nums.size()-1) {
                    update_tree (seg_tree, idx, i, 1);
                    continue;
                }
                
                val = search_tree (seg_tree, idx, i+1, nums[i]+i);
                if (val != numeric_limits<int>::max())
                    update_tree (seg_tree, idx, i, val+1);
            }

            return seg_tree[0];
        }

        void update_tree (vector<int>& seg_tree, vector<int>& idx, int pos, int val) {
            int i = 1;
            while (i < idx.size() && seg_tree[pos] > val) {
                seg_tree[pos] = val;
                pos = (pos-idx[i-1])/2 + idx[i];
                i++;
            }
        }

        /* inclusive: [first, last] */
        int search_tree (vector<int>& seg_tree, vector<int>& idx, int first, int last) {
            int min_val = numeric_limits<int>::max();
            int i = 1, tf, tl;
            while (last >= first+3) {
                tf = first - idx[i-1];
                tl = last - idx[i-1];
                if (tf & 1) {
                    if (min_val > seg_tree[first]) min_val = seg_tree[first];
                    tf++;
                }
                if (!(tl & 1)) {
                    if (min_val > seg_tree[last]) min_val = seg_tree[last];
                    tl--;
                }
                first = tf/2 + idx[i];
                last = tl/2 + idx[i];
                i++;
            }
            int min2 = *std::min_element(seg_tree.begin()+first, seg_tree.begin()+last+1);
            if (min2 < min_val) min_val = min2;

            return min_val;
        }
};

/*
 * input: vector<int> ## int
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
    vector<int> vi;
    int ret, expected;

    while (true) {
        cin >> vi;
        if (cin.eof()) break;
        cin >> buf >> expected;
        ret = Solution().jump(vi);
        if (ret != expected) {
            err = 1;
            cout << "input: " << vi << endl
                 << "ret: " << ret << endl
                 << "expected: " << expected << endl << endl;
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
