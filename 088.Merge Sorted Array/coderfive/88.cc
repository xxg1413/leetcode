#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
#include <numeric>
using namespace std;


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

bool err = false;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	    int i = m-1, j = n-1, k = m+n-1;
	    while (i >= 0 && j >= 0) {
		    if (nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
		    else nums1[k--] = nums2[j--];
	    }
	    if (j >= 0)
		    std::copy (nums2.begin(), nums2.begin()+j+1, nums1.begin());
    }
};

void do_test (vector<int> v1, vector<int> v2) {
	static int counter = 0;
	int m = v1.size(), n = v2.size();
	vector<int> expected (v1), saved_v1(v1);
	v1.resize(m+n);
	Solution().merge(v1, m, v2, n);
	for (auto it = v2.begin(); it != v2.end(); it++)
		expected.push_back(*it);
	std::sort(expected.begin(), expected.end());
	counter++;
	if (expected != v1) {
		err = true;
		cout << "#" << counter << "\n";
		cout << "input: " << v1 << ", " << v2 << "\n"
		     << "expected: " << expected << "\n"
		     << "got: " << v1 << "\n\n";
	}
}

int main() {
	do_test ({1}, {2});
	do_test ({}, {1});
	do_test ({2}, {});
	do_test ({1,2},{1,2});
	if (!err)
		cout << "All tests passed!\n";

	return 0;
}
