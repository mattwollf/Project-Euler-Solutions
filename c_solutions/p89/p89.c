#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fromRoman(const char *in);
int toRoman(const int in, char ** out);

char* romanHelper(int n, char *leader, char *five, char *ten)
{
	char *str = calloc(sizeof(char) , 5);

	switch(n % 10)
	{
		case 1:
		strcat(str, leader);
		break;
		case 2:
		strcat(str, leader);
		strcat(str, leader);
		break;
		case 3:
		strcat(str, leader);
		strcat(str, leader);
		strcat(str, leader);
		break;
		case 4:
		strcat(str, leader);
		case 5:
		strcat(str, five);
		break;
		case 6:
		strcat(str, five);
		strcat(str, leader);
		break;
		case 7:
		strcat(str, five);
		strcat(str, leader);
		strcat(str, leader);
		break;
		case 8:
		strcat(str, five);
		strcat(str, leader);
		strcat(str, leader);
		strcat(str, leader);
		break;
		case 9:
		strcat(str, leader);
		strcat(str, ten);
		default:
		return str;
	}
	return str;
}

int toRoman(const int in, char ** out)
{
	if(out == NULL){
		return -1;
	}

	int n = in;

	char *str = calloc(sizeof(char) , 20);
	char *ones;
	char *tens;
	char *huns;
	char *thou;
	char *tenk;

	// figure out numerals needed for 10
	ones = romanHelper(n, "I", "V", "X");
	n /= 10;

	tens = romanHelper(n, "X", "L", "C");
	n /= 10;

	huns = romanHelper(n, "C", "D", "M");
	n /= 10;

	for(int i = 0; i < n; i++)
	{
		strcat(str, "M");
	}

	strcat(str, huns);
	strcat(str, tens);
	strcat(str, ones);

	strcpy(*out, str);
}

int fromRoman(const char *in)
{
	int n = 0;

	int len = strlen(in);

	char curr;
	char next;

	for(int i = 0; i < len; i++)
	{
		curr = in[i];
		next = in[i+1];
		switch(curr)
		{
		case 'I':
			if( next == 'V'){
				n += 4;
				i++;
			}
			else if( next == 'X'){
				n += 9;
				i++;
			}
			else {
				n++;
			}
			break;
		case 'V':
			n += 5;
			break;
		case 'X':
			if( next == 'L'){
				n += 40;
				i++;
			}
			else if( next == 'C')
			{
				n += 90;
				i++;
			}
			else{
				n += 10;
			}
			break;

		case 'L':
			n += 50;
			break;
		case 'C':
			if(next == 'D'){
				n += 400;
				i++;
			}
			else if(next == 'M'){
				n += 900;
				i++;
			}
			else {
				n += 100;
			}
			break;
		case 'D':
			n += 500;
			break;
		case 'M':
			n += 1000;
		} //switch
	} // for

	return n;
}

int main(int argc, char *argv[])
{
	FILE * fin = NULL;
	FILE * fout = NULL;

	fin = fopen("roman.txt" , "r");
	if(fin == NULL) perror("couldn't open romans.txt\n");

	fout = fopen("out.txt" , "w");

	char *buf = malloc(sizeof(char) * 50);

	int sum = 0;
	int inLength;
	int outLength;

	int num;

	while( !feof(fin))
	{
		fgets(buf, 50, fin);
		inLength = strlen(buf) - 1;

		printf("parsing %slength %d ", buf, inLength);

		num = fromRoman(buf);

		printf("to: %d ", num);

		toRoman(num, &buf);
		outLength = strlen(buf);

		fputs(buf, fout);
		fputc('\n', fout);

		printf("and generated <%s>, length %d\n", buf, outLength);

		sum += (inLength - outLength);
	}
	fclose(fout);

	fclose(fin);
	printf("sum is: %d\n", sum);

	return 0;
}
