// Jogo de Mem�ria;
// Feito por Igor Sonehara e Lucas Cassiano;
// Programa��o II;
// Prof. Daniele Frosoni;

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <time.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>
#define TAM 6

void define_tamanho_tabuleiro(int *pQtdL, int *pQtdC)
{
    do
    {
        printf("Digite a quantidade de linhas do seu tabuleiro (>=3 e <=%d): ", TAM);
        scanf("%d", pQtdL);

        if(*pQtdL < 3 || *pQtdL > TAM)
        {
            printf("\nA quantidade de linhas esta fora do permitido...\n\n");
        }
    }
    while (*pQtdL < 3 || *pQtdL > TAM);

    do
    {
        printf("Digite a quantidade de colunas do seu tabuleiro (>=3 e <=%d): ", TAM);
        scanf("%d", pQtdC);

        if(*pQtdC < 3 || *pQtdC > TAM)
        {
            printf("\nA quantidade de colunas esta fora do permitido...\n\n");
        }
    }
    while (*pQtdC < 3 || *pQtdC > TAM);
}

void limparCampo(char tabuleiro[TAM][TAM])
{
    int l, c;
    for(l=0; l<TAM; l++)
    {
        for(c=0; c<TAM; c++)
        {
            tabuleiro[l][c] = '-';
        }
    }
}

void mostrar_tabuleiro(char tabuleiro[TAM][TAM], int qtdL, int qtdC)
{
    int l, c;

    printf("\n");

    printf("   ");
    for(c=0; c<qtdC; c++)
    {
        printf("%2i ", c+1);
    }
    printf("\n");
    for(l=0; l<qtdL; l++)
    {
        printf("%2i ", l+1);
        for(c=0; c<qtdC; c++) //
        {
            printf(" %c ", tabuleiro[l][c]);
        }
    printf("\n");
    }
}


int par_ou_impar(int qtdL, int qtdC)
{
    int parImpar = qtdL * qtdC;
    int Par, Impar;
    if ((qtdL * qtdC) % 2 == 0)
    {
        return parImpar;
    }
    else
    {
        return parImpar-1;
    }
}


void gerar_letras(char tabuleiro[TAM][TAM], int qtdL, int qtdC)
{
    srand((unsigned)time(NULL));
    int totalcelulas = par_ou_impar(qtdL, qtdC);
    int vetorletra[36] = {0};

    int g[36] = {'a','a','b','b','c','c','d','d','e','e','f','f','g','g','h','h','i','i','j','j','k','k','l','l','m','m','n','n','o','o','p','p','q','q','r','r'};
    int h[26] = {'?','a','a','b','b','c','c','d','d','e','e','f','f','g','g','h','h','i','i','j','j','k','k','l','l'};

    for(int q=0; q<36; q++)
    {
        if ((qtdL * qtdC) % 2 == 0)
        {
            vetorletra[q] = g[q];
        }
        else
        {
            vetorletra[q] = h[q];
        }
    }


    for (int s=0; s<(totalcelulas+1); s++)
    {
        for (int x=0; x<totalcelulas; x++)
        {
            //srand((unsigned)time(NULL));
            int i = rand()%totalcelulas;
            int temp = vetorletra[x];
            vetorletra[x] = vetorletra[i];
            vetorletra[i] = temp;
        }
    }
    int i=0;
    for(int r=0; r<qtdL; r++)
        {
            for (int c=0; c<qtdC; c++)
            {
                tabuleiro[r][c]=vetorletra[i];
                i=i+1;
            }
            printf("\n");
        }
}





void jogar(char tela[TAM][TAM], int qtdL, int qtdC, char tabuleiro[TAM][TAM])
{
    int numEscolhidoL1 = 0, numEscolhidoC1 = 0;
    int numEscolhidoL2 = 0, numEscolhidoC2 = 0;
    int numero_de_jogadas = 0;
    int jogada_certa = 0;
    int totalcelulas = par_ou_impar(qtdL, qtdC);
    int numEscolhidoAnteriorL1 = 0, numEscolhidoAnteriorC1 = 0;
    int numEscolhidoAnteriorL2 = 0, numEscolhidoAnteriorC2 = 0;


    system("cls");

    do{
    mostrar_tabuleiro(tela, qtdL, qtdC);
    printf("\nN�mero de jogadas = %i\n", numero_de_jogadas);
    printf("\nN�mero de acertos = %i\n", jogada_certa);


    do
    {
    printf("\n\nDigite a linha e a coluna que deseja jogar: ");//
    scanf("%d %d", &numEscolhidoL1, &numEscolhidoC1);//

    if(numEscolhidoL1<= 0 || numEscolhidoL1>qtdL || numEscolhidoC1<=0 || numEscolhidoC1>qtdC)//
    {
        printf("\nA posi��o escolhida est� fora dos limites do campo."); //
    }
    }while(numEscolhidoL1<= 0 || numEscolhidoL1>qtdL || numEscolhidoC1<=0 || numEscolhidoC1>qtdC);


    do
    {
    printf("\n\nDigite a linha e a coluna que deseja jogar: ");//
    scanf("%d %d", &numEscolhidoL2, &numEscolhidoC2);//

    if(numEscolhidoL2<= 0 || numEscolhidoL2>qtdL || numEscolhidoC2<=0 || numEscolhidoC2>qtdC)//
    {
        printf("\nA posi��o escolhida est� fora dos limites do campo."); //
    }
    else if(((numEscolhidoL1 == numEscolhidoL2) && (numEscolhidoC1 == numEscolhidoC2)))
    {
        printf("\nA posi��o escolhida ja foi selecionada anteriormente, tente outra posi��o...\n");
    }
    }while(numEscolhidoL2<= 0 || numEscolhidoL2>qtdL || numEscolhidoC2<=0 || numEscolhidoC2>qtdC || ((numEscolhidoL1 == numEscolhidoL2) && (numEscolhidoC1 == numEscolhidoC2)));




    if((tela[numEscolhidoL1-1][numEscolhidoC1-1] == '-') && (tela[numEscolhidoL2-1][numEscolhidoC2-1] == '-'  ))
    {
        if(tabuleiro[numEscolhidoL1-1][numEscolhidoC1-1] == tabuleiro[numEscolhidoL2-1][numEscolhidoC2-1])
        {
            numero_de_jogadas = numero_de_jogadas + 1;
            tela[numEscolhidoL1-1][numEscolhidoC1-1] = tabuleiro[numEscolhidoL1-1][numEscolhidoC1-1];
            tela[numEscolhidoL2-1][numEscolhidoC2-1] = tabuleiro[numEscolhidoL2-1][numEscolhidoC2-1];
            numEscolhidoAnteriorL1 = numEscolhidoL1, numEscolhidoAnteriorC1 = numEscolhidoC1;
            numEscolhidoAnteriorL2 = numEscolhidoL2, numEscolhidoAnteriorC2 = numEscolhidoC2;

            jogada_certa = jogada_certa + 1;

        }


        else if(tabuleiro[numEscolhidoL1-1][numEscolhidoC1-1] == '?' || tabuleiro[numEscolhidoL2-1][numEscolhidoC2-1] == '?')
        {
            tela[numEscolhidoAnteriorL1-1][numEscolhidoAnteriorC1-1] = '-';
            tela[numEscolhidoAnteriorL2-1][numEscolhidoAnteriorC2-1] = '-';
            //numero_de_jogadas = numero_de_jogadas + 1;
            if(jogada_certa > 0)
            {
                jogada_certa = jogada_certa - 1;
            }
            system("cls");

        }
        else
        {
            numero_de_jogadas = numero_de_jogadas + 1;

            tela[numEscolhidoL1-1][numEscolhidoC1-1] = tabuleiro[numEscolhidoL1-1][numEscolhidoC1-1];
            tela[numEscolhidoL2-1][numEscolhidoC2-1] = tabuleiro[numEscolhidoL2-1][numEscolhidoC2-1];
            mostrar_tabuleiro(tela, qtdL, qtdC);
            Sleep(3000);
            tela[numEscolhidoL1-1][numEscolhidoC1-1] = '-';
            tela[numEscolhidoL2-1][numEscolhidoC2-1] = '-';
            system("cls");

        }
    }
    else
    {
        printf("\nPosi��o j� marcada! Tente novamente...");
    }


void limparCampo(char campo[TAM][TAM])
{
    int l, c;
    for(l=0; l<TAM; l++)
    {
        for(c=0; c<TAM; c++)
        {
            campo[l][c] = '-';
        }
    }
}
}while(jogada_certa<totalcelulas/2);


    if(numero_de_jogadas <= ((qtdC*qtdL)*1.3))
    {
        printf("\nParab�ns, voc� tem boa mem�ria!!!\n");
    }
    else
    {
        printf("\nVoc� precisa treinar mais sua mem�ria!!!\n");
    }
}


int main()
{
    system("COLOR FD");
    setlocale(LC_ALL, "Portuguese");

    char tabuleiro[TAM][TAM];
    char tela[TAM][TAM];
    int qtdL = 0, qtdC = 0;
    define_tamanho_tabuleiro(&qtdL, &qtdC);
    //printf("\nTabuleiro = %d x %d\n", qtdL, qtdC);

    limparCampo(tabuleiro);
    //mostrar_tabuleiro(tabuleiro, qtdL, qtdC);
    par_ou_impar(qtdL, qtdC);
    gerar_letras(tabuleiro, qtdL, qtdC);
    //mostrar_tabuleiro(tabuleiro, qtdL, qtdC);//
    limparCampo(tela);
    mostrar_tabuleiro(tela, qtdL, qtdC);
    jogar(tela, qtdL, qtdC, tabuleiro);


    return 0;
}
