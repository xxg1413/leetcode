#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
#include <numeric>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0 || matrix[0].size() == 0) return res;
        int n = matrix[0].size(), i, j, m = matrix.size();
        int half = std::min(n, m) / 2;
        res.reserve(m*n);
        for (i = 0; i < half; i++) {
            std::copy (matrix[i].begin()+i, matrix[i].begin()+(n-i), std::back_inserter(res));
            for (j = i+1; j < m-i-1; j++)
                res.push_back (matrix[j][n-1-i]);
            std::copy (matrix[m-1-i].rbegin()+i, matrix[m-1-i].rbegin()+(n-i), std::back_inserter(res));
            for (j = m-i-2; j > i; j--)
                res.push_back (matrix[j][i]);
        }
        if (m <= n) {
            if (m & 1)
                std::copy (matrix[half].begin()+half, matrix[half].begin()+(n-half), std::back_inserter(res));
        }
        else {
            if (n & 1)
                for (i = half; i < m-half; i++)
                    res.push_back (matrix[i][half]);
        }

        return res;
    }
};

/*
 * input: vector<vector<int>> ## vector<int>
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
    vector<vector<int>> matrix;
    vector<int> ret, expected;

    while (true) {
        cin >> matrix;
        if (cin.eof()) break;
        cin >> buf >> expected;
        ret = Solution().spiralOrder(matrix);

        if (ret != expected) {
            err = 1;
            cout << "input: " << matrix << endl
                 << "ret: " << ret << endl
                 << "expected: " << expected << endl << endl;
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
