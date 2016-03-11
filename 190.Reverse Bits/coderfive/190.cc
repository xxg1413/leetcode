class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int a;
        for (int i = 0; i < 16; i++) {
            a = 0;
            if (n & (1<<i)) a = 1;
            if (n & (1<<(31-i)))
                n |= 1<<i;
            else
                n &= ~(1<<i);
            if (a)
                n |= 1<<(31-i);
            else
                n &= ~(1<<(31-i));
        }
        return n;
    }
};
