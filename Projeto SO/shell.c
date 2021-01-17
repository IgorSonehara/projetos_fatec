#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <dirent.h>
#include <time.h>

int main(int argc, char * argv[], char * evnp[])
{

char comando[30];
char *arg[3];
char usuario[10];
char senha[10];
int pid;

int i = 3;
while(i != 0)
{
	printf("Digite o usuario: \n");
	gets(usuario);
	printf("Digite a senha: \n");
	gets(senha);

	if(strcmp(usuario, "root") != 0 || strcmp(senha, "fatecso") != 0)
	{
		printf("Usuario ou senha incorreto! Tente novamente...\n\n");
		i--;

		if(i == 0)
		{
			printf("Limite de tentativas excedido!\n");
			exit(0);
		}			
	}
	else
	{
		printf("\n");
		break;
	}

}

for( ; ; )
{
	printf("fatec> ");
	fgets(comando, 511, stdin);
	comando[strlen(comando) - 1] = 0;

	argv[0]=strtok(comando, " ");
	argv[1]=strtok(NULL, " ");
	evnp[2]=strtok(NULL, " ");

	if(strcmp(argv[0], "sair") == 0)
	{
		exit(0);
	}


	if (strcmp(argv[0], "mudar") == 0)
	{
		pid = fork();
		if(pid == 0)
		{
			execlp("./mudar", "./mudar", argv[1], NULL);
		}
		else
		{
			wait(NULL);
			continue;
		}
	}


	if(strcmp(argv[0], "local")==0)
	{
		pid = fork();
		if(pid == 0)
		{
			execlp("./local", "./local", argv[1], NULL);
		}
		else
		{
			wait(NULL);
			continue;
		}
	}

	if(strcmp(argv[0], "listar")==0)
	{
		pid = fork();
		if(pid == 0)
		{
			execlp("./listar", "./listar", argv[1], NULL);
		}
		else
		{
			wait(NULL);
			continue;
		}
	}



	if(strcmp(argv[0], "apagar")==0)
	{
		pid = fork();
		if(pid == 0)
		{
			execlp("./apagar", "./apagar", argv[1], NULL);
		}
		else
		{
			wait(NULL);
			continue;
		}
	}


	if(strcmp(argv[0], "criar") == 0) 
	{
		pid = fork();
		if(pid == 0)
		{
			execlp("./criar", "./criar", argv[1], NULL);
		}
		else
		{
			wait(NULL);
			continue;
		}
	}

	if(strcmp(argv[0], "remover") == 0) 
	{
		pid = fork();
		if(pid == 0)
		{
			execlp("./remover", "./remover", argv[1], NULL);
		}
		else
		{
			wait(NULL);
			continue;
		}
	}


	if(strcmp(argv[0], "copiar") == 0)
	{
		pid = fork();
		if(pid == 0)
		{
			execlp("./copiar", "./copiar", argv[1], evnp[2], NULL);
		}
		else
		{
			wait(NULL);
			continue;
		}
	}

	if(strcmp(argv[0], "data") == 0) 
	{
		pid = fork();
		if(pid == 0)
		{
			execlp("./data", "./data", argv[1], NULL);
		}
		else
		{
			wait(NULL);
			continue;
		}
	}

	if(strcmp(argv[0], "creditos") == 0) 
	{
		pid = fork();
		if(pid == 0)
		{
			execlp("./creditos", "./creditos", argv[1], NULL);
		}
		else
		{
			wait(NULL);
			continue;
		}
	}

	if(strcmp(argv[0], "ajuda") == 0) 
	{
		pid = fork();
		if(pid == 0)
		{
			execlp("./ajuda", "./ajuda", argv[1], NULL);
		}
		else
		{
			wait(NULL);
			continue;
		}
	}



	else
	{
		printf("Comando invalido \n");
	}

}
}