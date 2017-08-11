#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

int TAM = 0;
 
//Cria subArrays sobre a matrix e comparando os valores somados para
//tamanhos diferentes, retornando o maior valor encontrado.
int maiorSubArray(int* array, int* inicio, int* fim, int TAM)
{
    // valores utilizados:
    int soma = 0, maiorValor = INT_MIN, i;
 
    // checa os valores negativos caso ouver
    *fim = -1;
 
    // uma uma variavel "temporaria" para o inicio da posicao do contador:
    int inicio_temp = 0;
 
    for (i = 0; i < TAM; ++i)
    {
        soma += array[i];
        if (soma < 0)
        {
            soma = 0;
            inicio_temp = i+1;
        }
        else if (soma > maiorValor)
        {
            maiorValor = soma;
            *inicio = inicio_temp;
            *fim = i;
        }
    }

    if (*fim != -1)
        return maiorValor;
 
    maiorValor = array[0];
    *inicio = *fim = 0;
 
    // ACha o maior valor no Array:
    for (i = 1; i < TAM; i++)
    {
        if (array[i] > maiorValor)
        {
            maiorValor = array[i];
            *inicio = *fim = i;
        }
    }
    return maiorValor;
}
 
void acharMaiorValor(int **matrix)
{
    int maiorValor = INT_MIN;
 
    int esq, dir, i;
    int temp[TAM], soma, inicio, fim;
 
    // Cria a coluna da esquerda
    for (esq = 0; esq < TAM; ++esq)
    {
        // Coloca todos os elemntos de "temp" como '0'
        memset(temp, 0, sizeof(temp));
 
 		//Cria os retangulos passandos por parametro para o metodo "maiorSubArray":
        for (dir = esq; dir < TAM; ++dir)
        {
            for (i = 0; i < TAM; ++i)
				temp[i] += matrix[i][dir];

				// Manda o array de "temp" com os valores da dimensao do retangulo e no metodo
				// "maiorSubArray" calcula qual o maior valor dentro do retangulo que começa em "inicio" e termina em "fim":
				soma = maiorSubArray(temp, &inicio, &fim, TAM);

				//Apos o metodo acima, compara o valor de volta (maiorValor) com o ja presente:
				if (soma > maiorValor)
				{
					maiorValor = soma;

				}
        }
    }
 
    // Mostra na tela o maior valor
    printf("%d\n", maiorValor);
}
 

int main(int argc, char *argv[])
{
	//Le um "file", no caso com o nome de "entrada":
	//FILE* file = fopen ("Testes", "r");

	//Le um file generico de entrada:
	//FILE* file = fopen(argv[1], "r");

	int i = 0;
	int linha = 0;
	int coluna = 0;

	//Pega o tamanho da matrix:
	//fscanf(file, "%d", &TAM);
	
	//printf("%d\n", TAM);

	//Aloca na memória o tamanho da matrix:


    int valor_while = 3;
	while (scanf("%d", &TAM) != -1)
	{  
		int **matrix = (int **)malloc(TAM * sizeof(int*));
			for(i = 0; i < TAM; i++)
				matrix[i] = (int *)malloc(TAM * sizeof(int));

		for(linha=0; linha < TAM; linha++)
		{
			for(coluna=0; coluna < TAM; coluna++){
				//fscanf(file,"%d",&matrix[linha][coluna]);
				scanf("%d",&matrix[linha][coluna]);
				//Mostrar a matrix montada:
				//printf("Posicao: %d%d %d\n", linha,coluna,matrix[linha][coluna]);
			}
		}
		acharMaiorValor(matrix);
		//scanf("%d", &TAM);
		valor_while = valor_while-1;
		//TAM = TAM-1;    
	}
	//fclose (file);

	//Testes para verificar dados corretos (TAM, linha e coluna):
    //printf("%d\n", TAM);
    //printf("%d\n", linha);
    //printf("%d\n", coluna);
    //acharMaiorValor(matrix);
 
    return 0;
}