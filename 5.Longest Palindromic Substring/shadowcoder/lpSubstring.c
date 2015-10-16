static int my_palindrome(char *start, char *end)
{
    while (1) {
        if (*start != *end) return 0;
        if ((start == end) || ((end - start == 1) && (*end == *start))) return 1;
        start++;
        end--;
    }
}

static int my_maxlenpal(char *s, int slen, int i, int *my_max_glo, char **my_first_glo, char **my_second_glo)
{
	int j;
	char *start;
    for (j = 0, start = s;slen - j + 1 >= i; j++) {
        if (my_palindrome(start + j, start + j + i - 1)) {
			*my_max_glo = i;
			*my_first_glo = start + j;
			*my_second_glo = start + j + i - 1;
			return *my_max_glo;
            //start[j + i] = 0;
            //return start + j;
        }
    }	
	return 0;
}

char* longestPalindrome(char* s)
{
	int my_max_glo = 0;
	char *my_first_glo;
	char *my_second_glo;
    int len = strlen(s);

	int left = 1, right = len, mid;
    while (left <= right) {
		mid = (left + right) / 2;
		if (!my_maxlenpal(s, len, mid, &my_max_glo, &my_first_glo, &my_second_glo) && left < right) {
			mid += 1;
			my_maxlenpal(s, len, mid, &my_max_glo, &my_first_glo, &my_second_glo);
		}
		
		if (my_max_glo == mid) {
			left = mid + 1;
		} else if (mid > my_max_glo) {
			right = mid - 1;
		} else {
			break;
		}
    }

	char *buf = (char *)calloc(sizeof(char), my_max_glo + 1);
	memcpy(buf, my_first_glo, my_max_glo);
	return buf;
}
