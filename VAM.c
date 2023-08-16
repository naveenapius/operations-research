#include <stdio.h>
#include <stdlib.h>
#define SRCS 3  //number of sources
#define DSTS 3  //number of destinations


/*
Finding initial basic feasible solution of transportation problem using Vogel's Approximation Method
*/


int dem[DSTS+1], sup[SRCS+1], cm[SRCS+1][DSTS+1], RP[SRCS+1], CP[DSTS+1];


int initDests()
{
    //initialising global array DSTS
    int i;
    for(i=0; i<DSTS; i++)
    {
        printf("\nEnter demand at destination %d: ", i);
        scanf("%d", &dem[i]);
    }
    printf("\nInitialised demands at all destinations");
    return 0;
}


int initSrcs()
{
    //initialising global array SRCS
    int i;
    for(i=0; i<SRCS; i++ )
    {
        printf("\nEnter supply at source %d: ", i);
        scanf("%d", &sup[i]);
    }
    printf("\nInitialised supply at all sources");
    return 0;
}

int initMatrix()
{
    int i,j;
    for(i=0; i<SRCS; i++)
    {
        for(j=0; j<DSTS; j++)
        {
            printf("\nEnter cost of transport from src %d to dest %d: ", i,j);
            scanf("%d", &cm[i][j]);
        }
    }
    printf("\nInitialised cost matrix");
    return 0;
}

int showState()
{
    //display supply
    int s;
    printf("\n\nSupply:");
    for(s=0; s<SRCS; s++)
    {
        printf("\nSource %d: %d", s, sup[s]);
    }
    //display demand
    int d;
    printf("\n\nDemand: ");
    for(d=0; d<DSTS; d++)
    {
        printf("\nDestination %d: %d", d, dem[d]);
    }
    //display cost matrix
    printf("\n\nCurrent cost matrix: ");
    int i,j;
    printf("\n");
    for(i=0; i<SRCS+1; i++)
    {
        for(j=0; j<DSTS+1; j++)
        {
            printf("%d\t", cm[i][j]);
        }
        printf("\n");
    }
}

int checkBalance()
{
    int balance, supply=0, demand=0;
    int i,j; //loop variables
    for(i=0; i<SRCS; i++)
    {
        supply += sup[i];
    }
    for(j=0; j<DSTS; j++)
    {
        demand += dem[j];
    }
    balance = supply-demand;
    int disbalance=0;
    if(balance==0)
    {
        printf("\nDemand and Supply are balanced.");
        return 0;
    }
    else if(balance > 0)
    {
        printf("\nThere is a surplus of %d units", balance);
        sup[SRCS] = balance;
        return 1;
    }
    else if(balance < 0)
    {
        printf("\nThere is a shortage of %d units", balance);
        dem[DSTS] = balance;
        return 2;
    }
}

int penaltyCalc(int arr[], int l)
{
    int i,j,t, min_indx;
    for(i=0; i<l-1; i++)
    {
        for(j=i+1; j<l; j++)
        {
            min_indx=i;
            if(arr[j]<arr[i])
            {
                min_indx = j;
            }
            if(min_indx != i)
            {
                t = arr[i];
                arr[i] = arr[min_indx];
                arr[min_indx] = t;
            }
        }
    }
    int penalty;
    penalty = arr[1] - arr[0];
    return penalty;
}

int rowPenalties(int rows, int cols)
{
    int arr[cols];
    int i,j;
    for(i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
        {
            arr[j] = cm[i][j];
        }
        RP[i] = penaltyCalc(arr, cols);
    }
}

int colPenalties(int rows, int cols)
{
    int arr[rows];
    int i,j;
    for(i=0; i<cols; i++)
    {
        for(j=0; j<rows; j++)
        {
            arr[j] = cm[j][i];
        CP[i] = penaltyCalc(arr, rows);
        }
    }
}

int showPenalties(int rows, int cols)
{
    int i;
    //display row penalties
    printf("\nRow penalities: ");
    for(i=0; i<rows; i++)
    {
        printf("%d\t", RP[i]);
    }
    //display column penalties
    printf("\nColumn penalties: ");
    for(i=0; i<cols; i++)
    {
        printf("%d\t", CP[i]);
    }
    return 0;
}

int VAM(int rows, int cols)
{
    rowPenalties(rows, cols);
    colPenalties(rows, cols);
    showPenalties(rows, cols);
    return 0;
}

//MAIN
void main()
{
    //initialising supply and demand
    initSrcs();
    initDests();

    //initialising cost matrix
    initMatrix();

    //displaying current state
    showState();

    //checking balance and passing row and column limits to matrixMinima()
    int bal;
    bal = checkBalance();
    if (bal==1)
    {
        VAM(SRCS+1, DSTS);
    }
    else if (bal==2)
    {
        VAM(SRCS, DSTS+1);
    }
    else
    {
        VAM(SRCS, DSTS);
    }
}
//end