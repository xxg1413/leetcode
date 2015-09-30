#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
    struct Result {
        int less, greater, idx;
    };
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            vector<int> *v1 = &nums1, *v2 = &nums2;
            if (nums1.size() == 0)
                swap (v1, v2);
            int size = v1->size() + v2->size();
            Result res;
            res = find_half (v1, v2);
            if (res.idx == -1) {
                /* v2 cannot be empty */
                swap (v1, v2);
                res = find_half (v1, v2);
            }
            if ((size & 1) || res.greater < size/2)
                return static_cast<double> ((*v1)[res.idx]);
            int val = (*v1)[res.idx];
            int idx = res.idx+1;
            if (idx != v1->size()) {
                int less = idx + lower_bound (v2->begin(), v2->end(), (*v1)[idx]) - v2->begin();
                if (less == size/2)
                    return get_half (val, (*v1)[idx]);
            }
            idx = upper_bound (v2->begin(), v2->end(), val) - v2->begin();
            return get_half (val, (*v2)[idx]);
        }

        double get_half (int v1, int v2) {
            double retval = v1 + (v2 - v1)/2;
            if ((v1 ^ v2) & 1)
                retval += 0.5;
            return retval;
        }

        /*
         * v1.size != 0.
         * find index to v1, such that 
         * # elements less than v1[index] < n (when size(v1+v2) is odd, '<' --> '<=')
         * and # elements greater than v1[index] <= n;
         * if no such index, return {.idx = -1, };
         */
        Result find_half (vector<int> *v1, vector<int> *v2) {
            Result res;
            int size = v1->size() + v2->size();
            int half = size/2;
            res.idx = -1;
            int lo = 0, hi = v1->size(), mid;
            while (lo < hi) {
                mid = (lo+hi) / 2;
                res.less = (lower_bound (v1->begin()+lo, v1->begin()+hi, (*v1)[mid]) - v1->begin())
                           + (lower_bound (v2->begin(), v2->end(), (*v1)[mid]) - v2->begin());
                res.greater = (upper_bound (v1->begin()+lo, v1->begin()+hi, (*v1)[mid]) - v1->begin())
                              + (upper_bound (v2->begin(), v2->end(), (*v1)[mid]) - v2->begin());
                res.greater = size - res.greater;
                if (res.less < half || ((size&1) && res.less == half)) {
                    if (res.greater <= half) {
                        res.idx = mid;
                        return res;
                    }
                    if (lo == mid)
                        lo = mid+1;
                    else
                        lo = mid;
                }
                else {
                    hi = mid;
                }
            }

            return res;
        }
};

int get_vector (vector<int> & v) {
    int num, val;
    cin >> num;
    if (cin.eof()) return 1;

    v.clear();
    while (num--) {
        cin >> val;
        v.push_back(val);
    }

    return 0;
}

/*
 * input: (num int{num}){2} ## notes to be ignored
 */
int main() {
    vector<int> v1, v2;
    while (true) {
        if (get_vector (v1)) return 0;
        get_vector (v2);
        cout << Solution().findMedianSortedArrays(v1, v2) << endl;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;
}
