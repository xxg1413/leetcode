class Solution {
public:
    bool isHappy(int n) {
        vector<int> v;
        int sum, t;
        while (true) {
            if (n == 1) return true;
            if (std::find(v.begin(), v.end(), n) != v.end()) return false;
            v.push_back(n);
            sum = 0;
            while (n) {
                t = n % 10;
                n /= 10;
                sum += t*t;
            }
            n = sum;
        }

        return true;
    }
};
