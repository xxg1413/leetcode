class Solution {
public:
    int countPrimes(int n) {
        vector<int> v (n, 0);
        int res = 0;
        for (int i = 2; i < n; i++) {
            if (v[i] == 1) continue;
            res++;
            for (int j = 2; j*i < n; j++)
                v[j*i] = 1;
        } 

        return res;
    }
};
