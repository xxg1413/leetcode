int strStr(char* haystack, char* needle) 
{
	char *p = strstr(haystack, needle);
	if (NULL == p) return -1;
	return p - haystack;
}
