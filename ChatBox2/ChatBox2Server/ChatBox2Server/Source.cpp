#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void main(){
	FILE *f = fopen("F:\\GIT\\ChatBox\\ChatBox2\\source.bin", "rb+");
	while (1)
	{
		char str[256];
		if (fgets(str, 256, f) == 0)
			continue;
		if (str[0] == -52) continue;
		printf("Client: %s\n", str);
		str[0] = -52;
		char s[256];
		printf("Enter msg:");
		gets(s);
		//scanf("%s", s);
		fprintf(f, "%s\n", s);
		fflush(f);
	}
	fclose(f);
}