// shell.c

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
// mudar.c

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[1])
{
	if (chdir(argv[1]) != 0)
    {
		printf("Caminho inválido!\n");
    }
}

// local.c

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

// listar.c

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

// apagar.c

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

// criar.c 

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

// remover.c

#include <stdio.h>
#include <stdlib.h>
#include <sys/unistd.h>
#include <unistd.h>

int main(int argc, char *argv[1])
{
	if(rmdir(argv[1]) != 0)
	{
		printf("Erro ao remover pasta\n");
	}
}

// copiar.c 

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

// data.c

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

// creditos.c

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	puts("\n\t*** CRÉDITOS ***\n"
    "\nIGOR MECHI SONEHARA - 0040971723021"
    "\nANDRÉ ROCHA E SILVA - 0040971723048"
    "\nLUCAS GARCIA DA SILVA CASSIANO - 0040971723049"
    "\nTIAGO GONÇALVES PENA - 0040971723034\n");
}

// ajuda.c

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	puts("\n\t*** AJUDA ***\n"
    "\nComando > Exemplo\n"
    "\nmudar   > mudar /home/usuario/pastadesejada"
    "\nlocal   > local"
    "\nlistar  > listar"
    "\napagar  > apagar nomedoarquvo.txt"
    "\ncriar   > criar nomedapasta"
    "\nremover > remover nomedapasta"
    "\ncopiar  > copiar nomedoarquivo.txt /destinodoarquivo/novonomedoarquivo.txt"
    "\ndata    > data\n");
}