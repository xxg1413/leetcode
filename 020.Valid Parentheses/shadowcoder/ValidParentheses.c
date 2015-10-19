bool isValid(char* s) 
{
	char stack[2048] = {0};
	int sp = -1;
	while (*s) {
		if (*s == '{' || *s == '[' || *s == '(') 
				stack[++sp] = *s;
		else if (*s == ')') {
			if (stack[sp] == '(') sp--;
			else break;
		} else if (*s == ']') {
			if (stack[sp] == '[') sp--;
			else break;
		} else if (*s == '}') {
			if (stack[sp] == '{') sp--;
			else break;
		} else break;
		s++;
	}
	return !*s && sp == -1? 1 : 0;
}
