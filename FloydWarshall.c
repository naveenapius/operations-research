#include <stdio.h>
#include <stdlib.h>
#define ORDER 4
#define INF 100

//global matrix declaration
int matrix[ORDER][ORDER];
/*
Floyd Warshall Algorithm for traversing a weighted graph
let k->number of vertices => order of matrix
init matrix with weights - infinity for no direct path

repeat k times
    repeat i times
        repeat j times
            if A[i,j] < A[i,k] + A[k,j]
                A[i,j] = A[i,k] + A[k,j]

*/
int initWeights()
{
    int i,j,w;
    for(i=0; i<ORDER; i++)
    {
        for(j=0; j<ORDER; j++)
        {
            printf("\nEnter edge weight from %d to %d (-1 for no edge): ", i+1, j+1);
            scanf("%d", &w);
            if(w != -1)
                matrix[i][j] = w;
        }
    }
    return 0;
}


int showMatrix()
{
    printf("\nCurrent matrix: \n");
    int i,j;
    for(i=0; i<ORDER; i++)
    {
        for(j=0; j<ORDER; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int init()
{
    int i,j;
    for(i=0; i<ORDER; i++)
    {
        for(j=0; j<ORDER; j++)
        {
            matrix[i][j] = INF;
        }
    }
    return 0;
}

int FloydWarshall()
{
    int i, j, k, cmp;
    for(k=0; k<ORDER; k++)
    {
        for(i=0; i<ORDER; i++)
        {
            for(j=0; j<ORDER; j++)
            {
                cmp = matrix[i][k] + matrix[k][j];
                if(cmp < matrix[i][j])
                    matrix[i][j] = cmp;
            }
        }
        printf("\n-----------------------------------------------\n");
        printf("\nIteration %d complete: \n", k+1);
        showMatrix();
    }
}

int main()
{
    init();
    showMatrix();
    initWeights();
    showMatrix();
    FloydWarshall();
    return 0;
}