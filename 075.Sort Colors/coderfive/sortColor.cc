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
        void sortColors(vector<int>& nums) {
            int arr[3] = {0, 0, 0};
            for (auto n : nums)
                arr[n]++;
            arr[1] += arr[0];
            std::fill (nums.begin(), nums.begin()+arr[0], 0);
            std::fill (nums.begin()+arr[0], nums.begin()+arr[1], 1);
            std::fill (nums.begin()+arr[1], nums.end(), 2);
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
    bool err = false;
    string buf;
    vector<int> nums, expected, saved_input;

    while (true) {
        cin >> nums;
        if (cin.eof()) break;
        cin >> buf >> expected;
        saved_input = nums;
        Solution().sortColors(nums);
        if (expected != nums) {
            err = true;
            cout << "input: " << saved_input << endl
                 << "result: " << nums << endl
                 << "expected: " << expected << endl << endl;
        }
    }

    if (!err)
        cout << "All tests passed!\n";

    return 0;
}
