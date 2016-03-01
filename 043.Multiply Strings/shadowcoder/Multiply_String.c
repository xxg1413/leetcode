static void turnaround(char *str){
	int str_length = strlen(str);

	char temp;
	int i;
	for(i = 0;i < str_length / 2;i ++){
		temp = str[i];
		str[i] = str[str_length - 1 - i];
		str[str_length - 1 - i] = temp;
	}
}

char *multiply(char *multiplier, char *multiplicand)
{	
	int num1_length = strlen(multiplier);
	int num2_length = strlen(multiplicand);
	char *num1 = (char *)malloc(sizeof(char) * (num1_length + 1));
	char *num2 = (char *)malloc(sizeof(char) * (num2_length + 1));
	char *result = (char *)calloc(sizeof(char), num1_length + num2_length + 1);
	memcpy(num1, multiplier, num1_length + 1);
	memcpy(num2, multiplicand, num2_length + 1);
	turnaround(num1);
	turnaround(num2);

	int i,j,carry = 0,tem_num1,tem_num2;

	for(i = 0;i < num2_length;i ++){
		for(j = 0;j < num1_length;j ++){
			tem_num1 = num1[j] - '0';
			tem_num2 = num2[i] - '0';
			result[j + i] += (tem_num2 * tem_num1) % 10 + carry;
			carry = tem_num2 * tem_num1 > 9? tem_num2 * tem_num1 / 10 : 0;
			while(result[j + i] > 9){	//tem_num1 * tem_num2 <= 9 && tem_num1 * tem_num2 + carry > 9
				carry += 1;
				result[j + i] -= 10;
			}
		}
		int e = 0;
		while(carry){	//i == num2_length
			result[j + i + e] += carry;
			if(result[j + i + e] > 9){
				result[j + i + e] -= 10;
				carry = 1;
			}else
				carry = 0;
			e += 1;
		}
	}

	//change the result from Hexadecimal to string
	for(i = 0;i < num1_length + num2_length;i ++)
		result[i] += '0';

	//clear the end '0'
	char *p2mymulend = result + strlen(result) - 1;
	while(*p2mymulend == '0'){
		*p2mymulend-- = 0x00;
		if(p2mymulend - result == 0)
			break;
	}

	if(num1) free(num1);
	if(num2) free(num2);
	turnaround(result);

	return result;
}
