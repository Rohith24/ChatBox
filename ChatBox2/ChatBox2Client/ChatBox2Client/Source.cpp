#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(){
	FILE *f = fopen("F:\\GIT\\ChatBox\\ChatBox2\\source.bin", "rb+");
	char s[256];
	int no;
	memset(s, '\0', 256);
	printf("Enter msg:");
	gets(s);
	fseek(f, 0, 0);
	fread(&no, sizeof(int), 1, f);
	no++;
	fseek(f, 0, 0);
	fwrite(&no, sizeof(int), 1, f);
	fflush(f);
	fseek(f, (no - 1) * 256 + 4, 0);
	fwrite(s, 256, 1, f);
	fflush(f);
	while (1)
	{
		char str[256];
		memset(str, '\0', 256);
		fseek(f, 0, 0);
		fread(&no, sizeof(int), 1, f);
		if (no % 2 == 1) continue;
		fseek(f, (no-1) * 256 + 4, 0);
		if (fgets(str, 256, f) == 0)
			continue;
		if (str[0] == '\0') continue;
		printf("Server: %s\n", str);
		char s[256];
		memset(s, '\0', 256);
		printf("Enter msg:");
		gets(s);
		fseek(f, 0, 0);
		fread(&no, sizeof(int), 1, f);
		no++;
		fseek(f, 0, 0);
		fwrite(&no, sizeof(int), 1, f);
		fflush(f);
		fseek(f, (no - 1) * 256 + 4, 0);
		fwrite(s, 256, 1, f);
		fflush(f);
	}
	fclose(f);
	getchar();
}