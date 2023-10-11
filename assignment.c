#include <stdio.h>
#include <stdlib.h>
#define ORDER 3

int matrix[ORDER][ORDER];
/*
Assignment Problem

n x n matrix
Row reduction : 
find min of each row
all elements -  min(row)
Similarly perform column reduction
*/
int initMatrix()
{
    int i,j;
    for(i=0; i<ORDER; i++)
    {
        for(j=0; j<ORDER; j++)
        {
            printf("\nEnter current assignment from %d to %d: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
    return 0;
}

int showMatrix()
{
    int i,j;
    printf("\nCurrent Matrix: \n");
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

int findMin(int arr[])
{
    int min, len, i;
    min = arr[0];
    for(i=0 ; i<ORDER; i++)
    {
        if(arr[i] < min)
            min = arr[i];
    }
    //find minimum of array
    return min;
}

int rowReduce()
{
    //parse all elements in the row to an array
    // findmin(array)
    // parse through each element in the array and replace it with val-min
    int row[ORDER];
    int index=0, i, row_min;
    printf("\nRow reduction in progress...\n");
    while(index<ORDER)
    {
        for(i=0; i<ORDER; i++)
        {
            row[i] = matrix[index][i];
        }
        row_min = findMin(row);
        for(i=0 ; i<ORDER; i++)
        {
            matrix[index][i] -= row_min;
        }
        index++;
    }
    return 0;
}

int colReduce()
{
    int col[ORDER];
    int index=0, i, col_min;
    printf("\nColumn reduction in progress...\n");
    while(index<ORDER)
    {
        for(i=0; i<ORDER; i++)
        {
            col[i] = matrix[i][index];
        }
        col_min = findMin(col);
        for(i=0; i<ORDER; i++)
        {
            matrix[i][index] -= col_min;
        }
        index++;
    }
    return 0;
}

int main()
{
    initMatrix();
    showMatrix();
    rowReduce();
    showMatrix();
    colReduce();
    showMatrix();
    return 0;
}