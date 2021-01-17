#include <stdio.h>
#include <stdlib.h>
#include <sys/unistd.h>
#include <unistd.h>

int main(int argc, char *argv[1])
{
	if(unlink(argv[1]) != 0)
	{
		printf("Erro ao apagar o arquivo \n");
	}
}