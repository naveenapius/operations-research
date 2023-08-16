#include <stdio.h>

#define SRCS 3
#define DSTS 4
#define LIM 1000000000

/*
Least Cost/Matrix Minima method of finding initial basic solution for transportation problems
*/

int dem[DSTS+1], sup[SRCS+1], cm[SRCS+1][DSTS+1];


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

int breakCheck()
{
    int i;
    for(i=0; i<SRCS; i++)
    {
        if(sup[i] !=0)
            return 1;
    }
    for(i=0; i<DSTS; i++)
    {
        if(dem[i] !=0)
            return 1;
    }
    return 0;
}

int matrixMinima(int rows, int cols)
{
    //too lazy to doc this one
    int cost=0;
    int min,r,c,i,j;
    while(breakCheck())
    {
        min=cm[0][0]; r=0; c=0;
        for(i=0; i<rows; i++)
        {
            for(j=0; j<cols; j++)
            {
                if(cm[i][j] < min)
                {
                    min = cm[i][j];
                    r=i; c=j;
                }
            }
        }
        if(sup[r] >= dem[c])
        {
            cost += (dem[c] * cm[r][c]);
            sup[r] -= dem[c];
            dem[c] =0;
        }
        else if(sup[r] < dem[c])
        {
            cost += (sup[r] * cm[r][c]);
            dem[c] -= sup[r];
            sup[r] = 0;
        }
        cm[r][c] = LIM;
    }
    printf("\nCost of initial basic feasible solution using Matrix Minima method: %d \n", cost);
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
        matrixMinima(SRCS+1, DSTS);
    }
    else if (bal==2)
    {
        matrixMinima(SRCS, DSTS+1);
    }
    else
    {
        matrixMinima(SRCS, DSTS);
    }
}