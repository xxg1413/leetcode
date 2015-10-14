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
        vector<int> plusOne(vector<int>& digits) {
            if (digits.size() == 0) {
                digits.push_back(1);
                return digits;
            }
            int i = digits.size()-1;
            while (i >= 0 && ++digits[i] == 10)
                digits[i--] = 0;
            if (i < 0) digits.insert (digits.begin(), 1);

            return digits;
        }
};

/*
 * input: vector<int> ## vector<int>
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
    vector<int> vi, saved_vi, ret, expected;

    while (true) {
        cin >> vi;
        if (cin.eof()) break;
        cin >> buf >> expected;
        saved_vi = vi;
        ret = Solution().plusOne(vi);
        if (ret != expected) {
            err = 1;
            cout << "input: " << saved_vi << endl
                 << "ret: " << ret << endl
                 << "expected: " << expected << endl << endl;
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
