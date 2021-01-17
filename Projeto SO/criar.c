#include <stdio.h>
#include <stdlib.h>
#include <sys/unistd.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[1])
{
	if(mkdir(argv[1], 0777) != 0)
	{
		printf("Erro ao criar pasta\n");
	}
}