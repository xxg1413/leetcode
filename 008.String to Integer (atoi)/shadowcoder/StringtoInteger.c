int myAtoi(char* str) {
    int i = 0, flag = 1;
    while(str[i] && str[i] == ' ') i += 1;
    if (!str[i]) return 0;
    if (str[i] == '-') {flag = -1;i+=1;}
    else if(str[i] == '+') i+= 1;
    
    if (!isdigit(str[i])) return 0;
    long long num = 0;
    sscanf(str + i, "%lld", &num);
    {
        if (flag > 0) {
            if (num > INT_MAX) return INT_MAX;
            else return num;
        } else {
            if (-num < INT_MIN) return INT_MIN;
            else return -num;
        }
    }
}
