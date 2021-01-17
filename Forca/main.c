// Versao corrigida
// Jogo da Forca
// Feito por Igor Mechi Sonehara
// Programação II
// Prof. Daniele Frosoni


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#define chave 25 // Chave da Cifra de Cesar
#define TAM 50

void verificarSeArquivoExiste()// Versao corrigida
// Jogo da Forca
// Feito por Igor Mechi Sonehara
// Programação II
// Prof. Daniele Frosoni


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#define chave 25 // Chave da Cifra de Cesar
#define TAM 50

void verificarSeArquivoExiste() // Se o arquivo não existir ele cria o arquivo sem apresentar mensagem de erro
{
    FILE *arq;
    arq = fopen("BancoDePalavras.txt", "r");

    char linha[TAM];
    int qtdPalavras = 0;
    int i;
    if(!arq)
    {
        arq = fopen("BancoDePalavras.txt", "w");


        itoa(qtdPalavras, linha, TAM);

        for(i=0; i<1; i++)
        {
            fputs(linha, arq);
            linha[0] = '\n';
            fputs(linha, arq);

            if(ferror(arq) != 0)
            {
                printf("\nErro.");
            }
        }
        fclose(arq);
    }

}

int verificarQtdPalavrasArquivo()
{
    FILE *arq;
    char linha[TAM];
    int qtdPalavras = 0;

    arq = fopen("BancoDePalavras.txt", "r");

    if(arq == NULL)
    {
        printf("\nErro ao abrir o arquivo.");
    }
    else
    {
        fgets(linha, TAM, arq);
        if(ferror(arq) != 0)
        {
            printf("\nErro - Não foi possível ler o arquivo.");
        }

        qtdPalavras = atoi(linha);
        fclose(arq);
    }

    return qtdPalavras;
}

void incrementarQtdPalavrasArquivo()
{
    FILE *arq;
    char linha[TAM];
    int qtdPalavras = 0;

    qtdPalavras = verificarQtdPalavrasArquivo();
    qtdPalavras++;

    arq = fopen("BancoDePalavras.txt", "r+");

    if(arq == NULL)
    {
        printf("\nErro ao abrir o arquivo.");
    }
    else
    {
        itoa(qtdPalavras, linha, TAM);    // converte int para string
        fputs(linha, arq);
        if(ferror(arq) != 0)
        {
            printf("\nErro - Não foi possível escrever a qtd no arquivo.");
        }

        fclose(arq);
    }
}

void escreverPalavraFimArquivo(char _palavra[TAM])
{
    FILE *arq;

    arq = fopen("BancoDePalavras.txt", "a");

    if(arq == NULL)
    {
        printf("\nErro ao abrir o arquivo.");
    }
    else
    {
        // Criptografar
        encriptar(_palavra);
        fputs(_palavra, arq);
        if(ferror(arq) != 0)
        {
            printf("\nErro - Não foi possível escrever a palavra no arquivo.");
        }

        fclose(arq);
    }
}

void adicionarPalavraNoArquivo()
{
    char _palavra[TAM];

    printf("\nDigite a PALAVRA: ");
    fflush(stdin);
    fgets(_palavra, TAM, stdin);
    strupr(_palavra);

    // Verificar a qtd de palavras do arquivo
    int res = verificarQtdPalavrasArquivo();
    printf("%d", res+1);

    // Armazenar a palavra no final do arquivo
    escreverPalavraFimArquivo(_palavra);

    // Incrementar a qtd de palavras do arquivo
    incrementarQtdPalavrasArquivo();

}

void configurarJogo()
{
    char opcao = ' ';
    char c = ' ';

    while(opcao != 'B')
    {
        system("cls");
        printf("*JOGO DA FORCA*\n\n");

        printf(">>> CONFIGURAÇÃO DO JOGO:\n\n");

        printf("Escolha uma opção:\n");
        printf("A) Adicionar nova palavra ao jogo.\n");
        printf("B) Concluir configuração.\n\n");

        printf("Opção escolhida: ");
        fflush(stdin);
        scanf("%c", &opcao);
        opcao = toupper(opcao);

        switch(opcao)
        {
            case 'A':
                adicionarPalavraNoArquivo();
                break;
            case 'B':
                break;
            default:
                printf("Opção inválida! Tecle para continuar...");
                fflush(stdin);
        }
        scanf("%c", &c);
    }
}

void menu()
{
    int opcao=0;
    char c;

    while(opcao != 3)
    {
        system("cls");
        printf("*JOGO DA FORCA*\n\n");

        printf(">>> MENU:\n\n");

        printf("1) Configuração do Jogo\n");
        printf("2) Jogar\n");
        printf("3) Sair\n\n");

        printf("Digite a opção que deseja escolher: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                configurarJogo();
                break;
            case 2:
                iniciarJogo();
                break;
            case 3:
                break;
            default:
                printf("Opção inválida! Tecle para continuar...");
                fflush(stdin);
                scanf("%c", &c);
        }
    }
}

int iniciarJogo()
{
    // Buscar palavra escolhida no arquivo

	FILE *arq;
    arq = fopen("BancoDePalavras.txt", "r");

    if(arq == NULL)
    {
        printf("\nErro ao abrir o arquivo.");
    }

    else
    {
    	int qtdPalavras = verificarQtdPalavrasArquivo();

		if(!qtdPalavras) // Se não houver palavras no arquivo ele volta para o menu
        {
            printf("Voce precisa adicionar ao menos uma palavra no banco de dados!\n");
            Sleep(2500);
            menu();
            //system("pause");
        }

		srand(time(NULL));
		int numero_aleatorio = 1 + rand() % qtdPalavras;
	    int i;

        if(qtdPalavras) // Caso haja ao menos uma palavra no arquivo, ele sorteia um número aleatório entre 1 e o número de palavras no arquivo
        {
        	char palavra[TAM];
            for(i=0; i<numero_aleatorio+1; i++)
            {
                fgets(palavra, TAM, arq);

                if(ferror(arq) != 0)
                {
                    printf("\nErro - Não foi possível ler o arquivo.");
                }
            }
            fclose(arq);

            // Decriptar palavra
    		desencriptar(palavra);

    		// Mostrar -s do tamanho da palavra
   			char palavra_oculta[TAM];
  			int i;

			for(i=0; i<strlen(palavra)-1; i++)
    		{
            	palavra_oculta[i] = '-';
            	palavra_oculta[strlen(palavra)-1] = '\0';
    		}

		jogar(palavra, palavra_oculta);
    	}
    }
}

int encriptar(char _palavra[TAM])
{
    char ch;
    int i;

    for(i = 0; _palavra[i] != '\0'; i++)
    {
        ch = _palavra[i];

        if(ch >= 'A' && ch <= 'Z')
        {
            ch = ch + chave;

            if(ch > 'Z')
            {
                ch = ch - 'Z' + 'A' - 1;
            }
            _palavra[i] = ch;
        }
    }
    //return _palavra;
}

int desencriptar(char palavra[TAM])
{
    char ch;
    int i;

    for(i = 0; palavra[i] != '\0'; i++)
    {
        ch = palavra[i];

        if(ch >= 'A' && ch <= 'Z')
        {
            ch = ch - chave;

            if(ch < 'A')
            {
                ch = ch + 'Z' - 'A' + 1;
            }
            palavra[i] = ch;
        }
    }
    //return palavra;
}

void jogar(char palavra[TAM], char palavra_oculta[TAM])
{
    char letra[2], letras_ja_selecionadas[TAM] = {'\0'}, corpo_do_boneco[3][3], letras_digitadas[TAM];
    int vida = 6, x, i, acertos = 0, contador = 0, vida_do_boneco = 0;

    // Limpa a matriz do boneco
    int linha, coluna;
    for(linha=0; linha<3; linha++)
    {
        for(coluna=0; coluna<3; coluna++)
        {
            corpo_do_boneco[linha][coluna] = '\0';
        }
    }

    while(vida <= 6)
    {
        system("cls");
        x = 0; // atribui 0 para a variavel x novamente

        printf("*JOGO DA FORCA*\n\n");
        printf(">>> A palavra secreta tem este tamanho:\n\n");
        printf(" %s \n\n", palavra_oculta);
        printf(">>> Lista de Letras já selecionadas: %s\n\n", letras_ja_selecionadas);

        if(vida != 6) // Só mostra o printf caso o jogador erre ao menos uma vez
        {
            printf(">>> Enforcado: \n\n");
        }

        for(linha=0; linha<3; linha++) // Mostra o boneco
        {
            printf("\t");
            for(coluna=0; coluna<3; coluna++)
            {
                printf("%c", corpo_do_boneco[linha][coluna]);
            }
            printf("\n");
        }
        printf("\n");


        if(vida == 0)
        {
            printf("\n\n VOCE FOI ENFORCADO!");
            printf("\n A PALAVRA ERA: %s", palavra);
            break;
        }

            printf("Digite a letra que deseja tentar advinhar: \n\n");
            //fflush(stdin);
            //fgets(letra, 2, stdin);
            //letra[0] = toupper(letra[0]);

        char c;
        do // Faz com que o usuário digite apenas letras (adaptei da internet)
        {
            c = getch(); //captura o caractere digitado pelo usuário
            if (isalpha(c) != 0 && c != 13) //se for uma letra
            {
                letra[0] = c;
                printf ("%c", c); //exibe o caractere digitado
            }
            else if(c == 8) //se for pressionada a tecla BACKSPACE e houver caracteres já digitados
            {
                letra[0] = '\0';
                printf("\b \b"); //o caractere digitado é apagado da tela
            }

        letra[0] = toupper(letra[0]);

        }while(c != 13); // Quando o ENTER for pressionado o loop é encerrado

        for(i=0; i<strlen(palavra); i++) // Verifica se a letra ja foi digitada
        {
            if(letra[0] == palavra[i] || letra[0] == letras_ja_selecionadas[i])
            {
                if(letra[0] == letras_digitadas[i] || letra[0] == letras_ja_selecionadas[i])
                {
                    printf("\nLetra inválida ou já digitada, tente novamente...\n");
                    Sleep(1500);
                    x++;
                    break;
                }
                else
                {
                letras_digitadas[i] = letra[0];
                //palavra_oculta[i] = palavra[i];
                palavra_oculta[i] = letra[0];
                acertos++;
                x++; // Adiciona 1 ao contador x, dessa forma ele não entra no if abaixo
                }
            }
        }

        if(x == 0) // Caso a letra escolhida não seja correta
        {

            vida--;
            vida_do_boneco++;
            letras_ja_selecionadas[contador] = letra[0]; // Exibe as letra incorretas
            letras_ja_selecionadas[contador-1] = '-'; // Adiciona os tracinhos entre as letras de forma que o tracinho nunca fica na direita da letra
            contador = contador + 2;


            switch (vida_do_boneco) // Conforme o jogador erra, o boneco vai aparecendo na tela
            {
                case 1:
                    corpo_do_boneco[0][1] = 'O';
                    break;
                case 2:
                    corpo_do_boneco[1][1] = '|';
                    break;
                case 3:
                    corpo_do_boneco[0][0] = '_';
                    break;
                case 4:
                    corpo_do_boneco[0][2] = '_';
                    break;
                case 5:
                    corpo_do_boneco[2][0] = '/';
                    break;
                case 6:
                    corpo_do_boneco[2][2] = '\\';
                    break;
            }

        }
        else if(acertos == strlen(palavra)-1) // Se o número de acertos for igual ao tamanho da palavra o jogador ganha
            {
                printf("\n\n VOCE GANHOU!");
                printf("\n A PALAVRA É: %s", palavra);
                break;
            }
    }
    printf("\n\n");
    system("pause");
}

int main()
{
    system("COLOR FD");
    setlocale(LC_CTYPE, "portuguese");

    verificarSeArquivoExiste();
    menu();

    return 0;
}
