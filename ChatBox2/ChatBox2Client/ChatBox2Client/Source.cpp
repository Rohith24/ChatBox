#include<stdio.h>
#include<stdlib.h>
void main(){
	FILE *f = fopen("F:\\GIT\\ChatBox\\ChatBox2\\source.bin", "rb+");
	char s[256];
	printf("Enter msg:");
	gets(s);
	fputs(s, f);
	fflush(f);
	while (1)
	{
		char str[256];
		if (fgets(str, 256, f) == 0)
			continue;
		if (str[0] == -52) continue;
		printf("Server: %s\n", str);
		str[0] = -52;
		char s[256];
		printf("Enter msg:");
		gets(s);
		//scanf("%s", s);
		fputs(s, f);
		fflush(f);
		//fflush(f);
	}
	fclose(f);
	getchar();
}