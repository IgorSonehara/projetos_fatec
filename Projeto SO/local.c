#include <stdio.h>
#include <stdlib.h>
#include <sys/unistd.h>
#include <unistd.h>

int main(void)
{
   	char dir[4096];
   	getcwd(dir, 4096);
   	printf("%s \n", dir);
}