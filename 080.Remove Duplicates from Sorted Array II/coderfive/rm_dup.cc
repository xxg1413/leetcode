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
        int removeDuplicates(vector<int>& nums) {
            if (nums.size() == 0) return 0;
            int i = 1, j = 1, sz = nums.size();
            while (j < sz) {
                while (j < sz && nums[j] != nums[j-1])
                    nums[i++] = nums[j++];
                if (j == sz) break;
                nums[i++] = nums[j++];
                while (j < sz && nums[j] == nums[j-1]) j++;
            }

            return i;
        }
};

/*
 * input: vector<int> ## int vector<int>
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
    vector<int> nums, saved_nums, expected_v;
    int expected_n, res;

    while (true) {
        cin >> nums;
        if (cin.eof()) break;
        cin >> buf >> expected_n >> expected_v;
        saved_nums = nums;

        res = Solution().removeDuplicates(nums);
        if (expected_n != res || 
                !std::equal (nums.begin(), nums.begin()+expected_n, expected_v.begin())) {
            err = true;
            cout << "input: " << saved_nums << endl
                 << "result: " << res << " " << nums << endl
                 << "expected: " << expected_n << " " << expected_v << endl << endl;
        }

    }

    if (!err)
        cout << "All tests passed!\n";

    return 0;
}
