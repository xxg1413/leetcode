#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
    public:
        int trap(vector<int>& height) {
            int i = 1, sum = 0, last_i = 0, res = 0;
            for (; i < height.size(); i++) {
                if (height[i] >= height[last_i]) {
                    res += (i-last_i-1) * height[last_i] - sum;
                    sum = 0;
                    last_i = i;
                }
                else
                    sum += height[i];
            }
            int end = last_i;
            sum = 0;
            last_i = height.size()-1;
            for (i = last_i-1; i >= end; i--) {
                if (height[i] >= height[last_i]) {
                    res += (last_i-i-1) * height[last_i] - sum;
                    sum = 0;
                    last_i = i;
                }
                else
                    sum += height[i];
            }

            return res;
        }
};

/*
 * input: vector<int> ## int
 */

istream& operator >> (istream& in, vector<int>& vi) {
    int val;
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

ostream& operator << (ostream& out, vector<int>& vi) {
    out << "{";
    if (vi.size() != 0)
        out << vi[0];
    for (int i = 1; i < vi.size(); i++)
        out << ", " << vi[i];
    out << "}";
    return out;
}

int main() {
    int err = 0, ret, expected;
    string buf;
    vector<int> vi;

    while (true) {
        cin >> vi;
        if (cin.eof()) break;
        cin >> buf >> expected;

        ret = Solution().trap(vi);

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
