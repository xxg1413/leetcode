#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i = 0, si = 0, v = 0, accum = 0, lowest = 0;
        while (i < gas.size()) {
            while (i < gas.size() && gas[i] < cost[i]) {
                accum += gas[i]-cost[i];
                i++;
            }
            if (accum < lowest) lowest = accum;
            si = i;
            v = 0;
            while (i < gas.size() && v+gas[i]-cost[i] >= 0) {
                v += gas[i]-cost[i];
                accum += gas[i]-cost[i];
                i++;
            }
        }
        if (si >= gas.size()) return -1;
        if (v + lowest < 0) return -1;
        return si;
    }
};

int main() {
    vector<int> gas {1, 2}, cost {2, 1};
    std::cout << Solution().canCompleteCircuit(gas, cost) << std::endl;

    return 0;
}
