#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[1])
{
	if (chdir(argv[1]) != 0)
    {
		printf("Caminho inválido!\n");
    }
    char dir[4096];
   	getcwd(dir, 4096);
   	printf("%s \n", dir);
}
