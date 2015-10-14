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
        void rotate(vector<vector<int>>& matrix) {
            int n = matrix.size();
            for (int i = 0; i < n/2; i++) {
                for (int j = i; j < n-i-1; j++) {
                    std::swap (matrix[i][j], matrix[j][n-1-i]);
                    std::swap (matrix[i][j], matrix[n-i-1][n-j-1]);
                    std::swap (matrix[i][j], matrix[n-j-1][i]);
                }
            }
        }
};

/*
 * input: vector<vector<int>> ## vector<vector<int>>
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
    vector<vector<int>> vi, saved_vi, expected;

    while (true) {
        cin >> vi;
        if (cin.eof()) break;
        cin >> buf >> expected;
        saved_vi = vi;
        Solution().rotate(vi);
        if (vi != expected) {
            err = 1;
            cout << "input: " << saved_vi << endl
                 << "ret: " << vi << endl
                 << "expected: " << expected << endl << endl;
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
