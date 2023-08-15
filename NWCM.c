#include <stdio.h>
#define DSTS 5  //number of destinations
#define SRCS 3   //number of sources


/*
North West Corner Method of obtaining initial basic feasible solution for transportation problems
*/



int dsts[DSTS], srcs[SRCS], cm[SRCS][DSTS];



int initDests()
{
    //initialising global array DSTS
    int i;
    for(i=0; i<DSTS; i++)
    {
        printf("\nEnter demand at destination %d: ", i);
        scanf("%d", &dsts[i]);
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
        printf("\nEnter supply at source %d: ". i);
        scanf("%d", &srcs[i]);
    }
    printf("\nInitialised supply at all sources: ");
    return 0;
}

int initMatrix()
{
    //initialising cost matrix
    return 0;
}

int checkBalance()
{
    int balance;
    return balance;
}


int NWCM()
{
    //running algorithm to obtain initial basic feasible solution
    int cost;
    return cost;
}







//MAIN
int main()
{
    //pass
    
}