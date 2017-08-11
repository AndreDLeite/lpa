// Program to find maximum sum subarray in a given 2D array
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
//#define ROW 4
//#define COL 4
int TAM = 0;
 
// Implementation of Kadane's algorithm for 1D array. The function 
// returns the maximum sum and stores starting and ending indexes of the 
// maximum sum subarray at addresses pointed by start and finish pointers 
// respectively.
int kadane(int* arr, int* start, int* finish, int n)
{
    // initialize sum, maxSum and
    int sum = 0, maxSum = INT_MIN, i;
 
    // Just some initial value to check for all negative values case
    *finish = -1;
 
    // local variable
    int local_start = 0;
 
    for (i = 0; i < n; ++i)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
            local_start = i+1;
        }
        else if (sum > maxSum)
        {
            maxSum = sum;
            *start = local_start;
            *finish = i;
        }
    }
 
     // There is at-least one non-negative number
    if (*finish != -1)
        return maxSum;
 
    // Special Case: When all numbers in arr[] are negative
    maxSum = arr[0];
    *start = *finish = 0;
 
    // Find the maximum element in array
    for (i = 1; i < n; i++)
    {
        if (arr[i] > maxSum)
        {
            maxSum = arr[i];
            *start = *finish = i;
        }
    }
    return maxSum;
}
 
// The main function that finds maximum sum rectangle in M[][]
void findMaxSum(int **mat1)
{
    // Variables to store the final output
    int maxSum = INT_MIN, finalLeft, finalRight, finalTop, finalBottom;
 
    int left, right, i;
    int temp[TAM], sum, start, finish;
 
    // Set the left column
    for (left = 0; left < TAM; ++left)
    {
        // Initialize all elements of temp as 0
        memset(temp, 0, sizeof(temp));
 
        // Set the right column for the left column set by outer loop
        for (right = left; right < TAM; ++right)
        {
           // Calculate sum between current left and right for every row 'i'
            for (i = 0; i < TAM; ++i)
                temp[i] += mat1[i][right];
 
            // Find the maximum sum subarray in temp[]. The kadane() 
            // function also sets values of start and finish.  So 'sum' is 
            // sum of rectangle between (start, left) and (finish, right) 
            //  which is the maximum sum with boundary columns strictly as
            //  left and right.
            sum = kadane(temp, &start, &finish, TAM);
 
            // Compare sum with maximum sum so far. If sum is more, then 
            // update maxSum and other output values
            if (sum > maxSum)
            {
                maxSum = sum;
                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = finish;
            }
        }
    }
 
    // Print final values
    printf("(Top, Left) (%d, %d)\n", finalTop, finalLeft);
    printf("(Bottom, Right) (%d, %d)\n", finalBottom, finalRight);
    printf("Max sum is: %d\n", maxSum);
}
 
// Driver program to test above functions
int main()
{
    /*
    int M[ROW][COL] = {{1, 2, -1, -4, -20},
                       {-8, -3, 4, 2, 1},
                       {3, 8, 10, 1, 3},
                       {-4, -1, 1, 7, -6}
                      };
    */
	FILE* file = fopen ("1234", "r");

	int i = 0;
	//int TAM = 0;
	int linha = 0;
	int coluna = 0;

	fscanf(file, "%d", &TAM);

    int **mat1 = (int **)malloc(TAM * sizeof(int*));
    for(i = 0; i < TAM; i++)
        mat1[i] = (int *)malloc(TAM * sizeof(int));

	while (!feof (file))
	{  
		//printf ("%d ", i);
		for(linha=0; linha < TAM; linha++)
		{
			for(coluna=0; coluna < TAM; coluna++){
				fscanf(file,"%d",&mat1[linha][coluna]);
				printf("Posicao: %d%d %d\n", linha,coluna,mat1[linha][coluna]);
			}
		}
		//fscanf (file, "%d\n", &i);      
	}
	fclose (file);

    int M[4][4] = {{0, -2, -7, 0}, {9, 2, -6, 2}, {-4, 1, -4, 1}, {-1, 8, 0, -2}};
    //printf("%d\n", TAM);
    //printf("%d\n", linha);
    //printf("%d\n", coluna);
    findMaxSum(mat1);
    //findMaxSum(M);
 
    return 0;
}