#include <stdio.h>
#include <stdlib.h>
#include <sys/unistd.h>
#include <unistd.h>
#include <dirent.h>

int main(void)
{
	DIR *dir;
	struct dirent *sd;
	dir = opendir(".");

	if(dir == NULL)
	{
		printf("Erro, o diretorio nao existe!\n");
	}
	while((sd=readdir(dir)) != NULL )
	{
		printf(">> %s\n", sd->d_name);
	}
	closedir(dir);
}