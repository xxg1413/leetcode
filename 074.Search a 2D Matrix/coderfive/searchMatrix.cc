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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int i = 0, j = matrix.size(), mid;
        while (i < j) {
            mid = (i+j)/2;
            if (matrix[mid][0] > target)
                j = mid;
            else if (matrix[mid].back() < target)
                i = mid+1;
            else
                return std::binary_search (matrix[mid].begin(), matrix[mid].end(), target);
        }
        return false;
    }
};

/*
 * input: vector<vector<int>> int ## true|false
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
    vector<vector<int>> matrix;
    int target;
    bool res, expected;
    cout.setf(std::ios_base::boolalpha);

    while (true) {
        cin >> matrix;
        if (cin.eof()) break;
        cin >> target >> buf >> buf;
        if (buf == "true")
            expected = true;
        else
            expected = false;
        res = Solution().searchMatrix(matrix, target);
        if (res != expected) {
            err = true;
            cout << "input: " << matrix << "  " << target << endl
                 << "result: " << res << endl
                 << "expected: " << expected << endl << endl;
        }
    }

    if (!err)
        cout << "All tests passed!\n";

    return 0;
}
