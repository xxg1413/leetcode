class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == n) return m;
        int i = 30;
        while (((m & (1<<i)) == ((n & (1<<i))))) i--;
        return m & ~((1<<i) | ((1<<i)-1));
    }
};
