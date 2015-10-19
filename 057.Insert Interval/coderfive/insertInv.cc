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
        vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
            auto it = std::lower_bound (intervals.begin(), intervals.end(), newInterval, 
                    [] (const Interval& lhs, const Interval& rhs) { return lhs.end < rhs.start; });
            if (it == intervals.end()) {
                intervals.push_back (Interval(newInterval.start, newInterval.end));
                return intervals;
            }
            
            int idx = it-intervals.begin();
            if (newInterval.end < intervals[idx].start) {
                intervals.insert (intervals.begin()+idx, newInterval);
                return intervals;
            }
            intervals[idx].start = std::min(intervals[idx].start, newInterval.start);
            intervals[idx].end = std::max(intervals[idx].end, newInterval.end);

            int j = idx+1;
            while (j < intervals.size() && intervals[j].start <= intervals[idx].end) {
                if (intervals[idx].end <= intervals[j].end) {
                    intervals[idx].end = intervals[j++].end;
                    break;
                }
                j++;
            }
            if (idx+1 < j)
                intervals.erase (intervals.begin()+idx+1, intervals.begin()+j);

            return intervals;
        }
};

/*
 * input: vector<Interval> Interval ## vector<Interval>
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
    vector<Interval> vi, saved_vi, expected, ret;
    Interval inv;

    while (true) {
        cin >> vi;
        if (cin.eof()) break;
        cin >> inv >> buf >> expected;
        saved_vi = vi;
        ret = Solution().insert(vi, inv);
        if (ret != expected) {
            err = 1;
            cout << "input: " << saved_vi << "  " << inv << endl
                 << "ret: " << ret << endl
                 << "expected: " << expected << endl << endl;
        }
    }

    if (err == 0)
        cout << "All tests passed!\n";

    return 0;
}
