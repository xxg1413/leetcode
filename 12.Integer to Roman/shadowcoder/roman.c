#include "head.h"
int lt1000(char *result, int num, int level, char n1, char n2, char n3)
{
	int k = 0;
	while (num >= level) {
		if (num >= 9 * level) {
			result[k++] = n1;
			result[k++] = n3;
			num -= 9 * level;
		} else if(num >= 5 * level) {
			result[k++] = n2;
			num -= 5 * level;
		} else if(num >= 4 * level) {
			result[k++] = n1;
			result[k++] = n2;
			num -= 4 * level;
		} else if(num >= level) {
			while (num >= level) {
				result[k++] = n1;
				num -= level;
			}
		}
	}
	return k;
}
char* intToRoman(int num) 
{
	int k = 0;
	static char out[16];
	while (num >= 1000) {
		out[k++] = 'M';
		num -= 1000;
	}
	if(num >= 100) k += lt1000(out + k, num % 1000, 100, 'C', 'D', 'M');
	if(num >= 10) k += lt1000(out + k, num % 100, 10, 'X', 'L', 'C');
	if(num >= 1) k += lt1000(out + k, num % 10, 1, 'I', 'V', 'X');
	out[k] = 0;
	return out;
}

int main(int argc, char *argv[])
{
	//printf("%s\n", intToRoman(atoi(argv[1])));
	printf("%s\n", intToRoman(1000));
	return 0;
}
