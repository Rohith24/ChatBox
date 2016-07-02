#include<stdio.h>
#include<stdlib.h>
void main(){
	FILE *fser = fopen("F:\\GIT\\ChatBox\\ChatBox1\\server.bin", "wb+");
	FILE *fclinet = fopen("F:\\GIT\\ChatBox\\ChatBox1\\client.bin", "rb+");
	char s[256];
	printf("Enter msg:");
	gets(s);
	//scanf("%s", s);
	fputs(s, fser);
	//fprintf(fser, "%s\n", s);
	fflush(fser);
	while (1)
	{
		char str[256];
		if (fgets(str,256,fclinet) == 0)
			continue;
		if (str[0] == -52) continue;
		printf("Client: %s\n", str);
		str[0] = -52;
		char s[256];
		printf("Enter msg:");
		gets(s);
		//scanf("%s", s);
		fputs(s, fser);
		fflush(fser);
		//fflush(fclinet);
	}
	fclose(fclinet);
	fclose(fser);
	getchar();
}