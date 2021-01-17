#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    time_t t = time(NULL);
   	struct tm *tm = localtime(&t);
   	char s[64];
   	strftime(s, sizeof(s), "%c", tm);
	printf("%s\n", s);
}