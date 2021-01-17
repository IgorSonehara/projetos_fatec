#include <stdio.h>
#include <stdlib.h>
#include <sys/unistd.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[1], char *evnp[2])
{
	int srcFD,destFD,nbread,nbwrite;
	char *buff[1024];
	
	srcFD = open(argv[1],O_RDONLY);

	if(srcFD == -1)
	{
		printf("Erro ao copiar o arquivo\n");
	}
	
	destFD = open(evnp[2],O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
 
	if(destFD == -1)
	{
		printf("Erro ao copiar o arquivo\n");
	}
 
	while((nbread = read(srcFD,buff,1024)) > 0)
	{
		if(write(destFD,buff,nbread) != nbread)
		{
			printf("Erro ao copiar o arquivo");
		}
	}
}