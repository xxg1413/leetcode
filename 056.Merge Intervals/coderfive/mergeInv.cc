#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
#include <limits>
#include <numeric>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
    public:
        vector<Interval> merge(vector<Interval>& intervals) {
            if (intervals.size() < 2) return intervals;
            std::sort (intervals.begin(), intervals.end(), 
                    [] (const Interval& lhs, const Interval& rhs) { return lhs.start < rhs.start; });
            int start = 0, i = 1;
            for (; i < intervals.size(); i++) {
                if (intervals[start].end >= intervals[i].start) {
                    if (intervals[start].end < intervals[i].end)
                        intervals[start].end = intervals[i].end;
                }
                else {
                    intervals[start+1].start = intervals[i].start;
                    intervals[start+1].end = intervals[i].end;
                    start++;
                }
            }

            intervals.resize(start+1);

            return intervals;
        }
};

/*
 * input: vector<Interval> ## vector<Interval>
 * Interval: [int, int]
 */

istream& operator >> (istream& in, Interval& inv) {
    while (!in.eof() && isspace(in.peek())) in.get();
    if (in.eof()) return in;
    if (in.peek() != '[') return in;
    in.get();
    in >> inv.start;
    while (!in.eof() && in.get() != ',');
    if (in.eof()) return in;
    in >> inv.end;
    while (!in.eof() && in.get() != ']');

    return in;
}

ostream& operator << (ostream& out, Interval& inv) {
    out << '[' << inv.start << ", " << inv.end << ']';

    return out;
}

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

bool operator == (const Interval& lhs, const Interval& rhs) {
    return lhs.start == rhs.start && lhs.end == rhs.end;
}

int main() {
    int err = 0;
    string buf;
    vector<Interval> vi, saved_vi, ret, expected;

    while (true) {
        cin >> vi;
        if (cin.eof()) break;
        cin >> buf >> expected;
        saved_vi = vi;
        ret = Solution().merge(vi);
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
