#include <stdio.h>
#define DSTS 4  //number of destinations
#define SRCS 3   //number of sources


/*
North West Corner Method of obtaining initial basic feasible solution for transportation problems
*/



int dem[DSTS], sup[SRCS], cm[SRCS][DSTS];



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
    for(i=0; i<SRCS; i++)
    {
        for(j=0; j<DSTS; j++)
        {
            printf("%d\t", cm[i][j]);
        }
        printf("\n");
    }
}

int checkBalance()
{
    int balance;
    return balance;
}

    // i++;

int NWCM()
{
    //running algorithm to obtain initial basic feasible solution
    int row=0, col=0, i=1;
    int cost=0;
    while(row < SRCS && col < DSTS)
    {   
        // printf("\nIteration: %d", i);
        int supply=sup[row], demand=dem[col];
        if(supply >= demand)
        {
            supply -= demand;
            sup[row] = supply;
            cost += (demand * cm[row][col]);
            col++;
        }
        else if(supply < demand)
        {
            demand -= supply;
            dem[col] = demand;
            cost += (supply * cm[row][col]);
            row++;
        }
    // showState();
    // i++;
    }
    printf("\nCost using initial basic feasible solution obtained using NWCM: %d\n\n", cost);
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

    //showing current state
    showState();

    //running NWCM
    NWCM();
}
//end