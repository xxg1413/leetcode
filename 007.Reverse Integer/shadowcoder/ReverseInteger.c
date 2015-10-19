int reverse(int x) {
    char buf[16] = {0};
    snprintf(buf, 16, "%d", x);
    char *sta, *end;
    int flag = 1;
    sta = buf;
    if (buf[0] == '-') {
        flag = -1;
        sta += 1;
    } else if(buf[0] == '+') {
        sta += 1;
    }
    int len = strlen(sta);
    end = sta + len - 1;
    while (end - sta > 0) {
        int tmp = *sta;
        *sta = *end;
        *end = tmp;
        sta++; end--;
    }
    long long v;
    sscanf(buf, "%lld", &v);
    if (v > INT_MAX) return 0;
    if (v < INT_MIN) return 0;
    return atoi(buf);
}
