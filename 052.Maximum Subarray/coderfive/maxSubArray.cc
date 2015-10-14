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
        int maxSubArray(vector<int>& nums) {
            int sum = 0, idx = 0, max_sum = std::numeric_limits<int>::min();
            for (; idx < nums.size(); idx++) {
                sum += nums[idx];
                if (sum > max_sum) max_sum = sum;
                if (sum <= 0)
                    sum = 0;
            }

            return max_sum;
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
    int expected, ret;

    while (true) {
        cin >> vi;
        if (cin.eof()) break;
        cin >> buf >> expected;
        ret = Solution().maxSubArray(vi);

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
