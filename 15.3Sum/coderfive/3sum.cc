#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            if (nums.size() == 0) return vector<vector<int>>();
            vector<int> v(nums);
            vector<vector<int>> vvi;
            v.push_back(numeric_limits<int>::min());
            sort (v.begin(), v.end());
            if (v[0] == v[1]) v[0]++;

            int j, end;
            for (int i = 1; i < v.size(); i++) {
                while (i < v.size() && v[i] == v[i-1]) i++;
                for (j = i+1, end = v.size()-1; j < end;) {
                    if (v[i]+v[j] > 0 || v[end] < 0) break;
                    while (end > j && v[i]+v[j]+v[end] > 0) end--;
                    if (end > j && v[i]+v[j]+v[end] == 0) {
                        vvi.push_back(vector<int>({v[i], v[j], v[end]}));
                        end--;
                    }
                    while (++j < end && v[j] == v[j-1]);
                }
            }

            return vvi;
        }
};

/*
 * input: vector<int> ## vector<vector<int>>
 *        vector<type>: {}
 *                    | {type [,type]*}
 */

template<class T>
istream& operator >> (istream& is, vector<T>& v) {
    T val;
    int c;
    v.clear();
    while (!cin.eof() && isspace(cin.peek())) cin.get();
    if (cin.eof()) return is;

    if (cin.peek() == '{') cin.get();
    else return is;

    while (true) {
        cin >> val;
        v.push_back(val);
        while (isspace(c = cin.get()));
        if (c == '}') return is;
    }
    return is;
}

template<typename T> 
ostream& operator<<(ostream& out, vector<T>& v) {
    if (v.size() == 0) {
        out << "{}";
        return out;
    }
    out << "{" << v[0];
    for (typename::vector<T>::size_type i = 1; i < v.size(); i++)
        out << ", " << v[i];
    out << "}";

    return out;
}

int main() {
    int err = 0;
    string buf;
    vector<int> input, tmp;
    vector<vector<int>> res, ret, expected;

    while (true) {
        cin >> input;
        if (cin.eof()) break;
        cin >> buf;
        res.clear();
        cin >> res;

        ret = Solution(). threeSum(input);
        expected = res;

        for (auto v : ret) {
            auto it = res.begin();
            while (it != res.end() && *it != v) it++;
            if (it == res.end()) {
                err = 1;
                cout << "input: " << input << endl
                     << "ret: " << ret << endl
                     << "expected: " << expected << endl << endl;
                break;
            }
            else
                res.erase(it);
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
