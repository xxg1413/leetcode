double myPow(double x, int n) {
    int flag = 0;
    if (n == 0) 
        return fabs(x) < 0.000001? 0 : 1;
    if (n == INT_MIN)
        return fabs(x) >= 1.000000 && fabs(x) < 1.000001? 1:0;
    if (n < 0) {
        flag = 1;
        n = -n;
    }
	int lev[32] = {0};
	int i, nn = n;
	for (i = 1; i < 32; i++) {
		if (nn & 0x01) lev[i] = 1;
		nn >>= 1;
	}
    long double xx = 1;
    for (i = 1; i < 32; i++) {
		if (lev[i]) xx *= x;
		x *= x;
	}
    return flag? 1.0 / (double)xx : (double)xx;
}
