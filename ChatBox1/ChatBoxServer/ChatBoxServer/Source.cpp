#include<stdio.h>
#include<stdlib.h>
void main(){
	FILE *fclinet = fopen("F:\\GIT\\ChatBox\\ChatBox1\\client.bin", "wb+");
	FILE *fser = fopen("F:\\GIT\\ChatBox\\ChatBox1\\server.bin", "rb+");
	while (1)
	{
		char str[256];
		if (fgets(str,256,fser) == 0)
			continue;
		if (str[0] == -52) continue;
		printf("Server: %s\n", str);
		str[0] = -52;
		char s[256];
		printf("Enter msg:");
		gets(s);
		//scanf("%s", s);
		fprintf(fclinet, "%s\n", s);
		fflush(fclinet);
	}
	fclose(fclinet);
	fclose(fser);
}
