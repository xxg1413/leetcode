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
        void setZeroes(vector<vector<int>>& matrix) {
            if (matrix.size() == 0) return;
            int i, j, c0 = 1, r0 = 1;
            int rows = matrix.size(), cols = matrix[0].size();
            for (i = 0; i < cols; i++) {
                if (matrix[0][i] == 0)
                    r0 = 0;
                for (j = 1; j < rows; j++)
                    if (matrix[j][i] == 0)
                        matrix[0][i] = matrix[j][0] = 0;
            }
            for (i = cols-1; i >= 0; i--) {
                    for (j = 1; j < rows; j++)
                        if (matrix[0][i] == 0 || matrix[j][0] == 0)
                            matrix[j][i] = 0;
            }
            if (r0 == 0)
                std::fill (matrix[0].begin(), matrix[0].end(), 0);
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
    bool err = false;
    string buf;
    vector<vector<int>> matrix, saved_matrix, expected;

    while (true) {
        cin >> matrix;
        if (cin.eof()) break;
        cin >> buf >> expected;
        saved_matrix = matrix;
        Solution().setZeroes(matrix);
        if (expected != matrix) {
            err = true;
            cout << "input: " << saved_matrix << endl
                 << "result: " << matrix << endl
                 << "expected: " << expected << endl << endl;
        }
    }

    if (!err)
        cout << "All tests passed!\n";

    return 0;
}
