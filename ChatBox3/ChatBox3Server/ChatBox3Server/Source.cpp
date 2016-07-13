#include <windows.h>
#include <stdio.h>
#include <conio.h>

DWORD WINAPI ReadThread(LPVOID par){
	int prev = -1;
	while (1)
	{
		FILE *f = fopen("F:\\GIT\\ChatBox\\ChatBox3\\source.bin", "rb+");
		char str[256];
		int cno,sno;
		memset(str, '\0', 256);
		fseek(f, 0, 0);
		fread(&sno, sizeof(int), 1, f);
		fread(&cno, sizeof(int), 1, f);
		if (prev == cno){
			fclose(f);
			continue;
		}
		prev = cno;
		fseek(f, (sno+cno-1) * 256 + 8, 0);
		if (fread(str, 256, 1, f) == 0){
			fclose(f);
			continue;
		}
		if (str[0] == '\0'){
			fclose(f);
			continue;
		}
		printf("Client: %s\n", str);
	}
}

DWORD WINAPI WriteThread(LPVOID par)
{
	int cno,sno;
	while (1)
	{
		FILE *f = fopen("F:\\GIT\\ChatBox\\ChatBox3\\source.bin", "rb+");
		char s[256];
		memset(s, '\0', 256);
		gets(s);
		fseek(f, 0, 0);
		fread(&sno, sizeof(int), 1, f);
		fread(&cno, sizeof(int), 1, f);
		sno++;
		fseek(f, 0, 0);
		fwrite(&sno, sizeof(int), 1, f);
		fflush(f);
		fseek(f, (sno+cno - 1) * 256 + 8, 0);
		fwrite(s, 256, 1, f);
		fflush(f);
		fclose(f);
	}
}

void main(){
	FILE *f = fopen("F:\\GIT\\ChatBox\\ChatBox3\\source.bin", "rb+");
	DWORD dwThreadId, dwThrdParam = 1;
	HANDLE  hThreadArray[2];
	hThreadArray[0]=CreateThread(0, 0, ReadThread, 0, 0, 0);
	hThreadArray[1]=CreateThread(0, 0, WriteThread, 0, 0, 0);
	WaitForMultipleObjects(2, hThreadArray, TRUE, INFINITE);
	for (int i = 0; i<2; i++)
	{
		CloseHandle(hThreadArray[i]);
	}
	fclose(f);
}