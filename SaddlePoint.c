#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 3


int POM[ROWS+1][COLS+1];

void createMatrix()
{
	//inputs payoff matrix
	int i,j,c;
	for(i=0; i<ROWS; i++)
	{
		for(j=0; j<COLS; j++)
		{
			printf("\nEnter payoff from %d to %d: ",i+1, j+1);
			scanf("%d",&c);
			POM[i][j] = c;
		}
	}
	return;
}


void showMatrix()
{
	//shows current payoff matrix
	printf("\n\nPayoff Matrix: \n");
	
	int i,j;
	for(i=0; i<ROWS+1; i++)
	{
		for(j=0; j<COLS+1; j++)
		{
			printf("%d\t", POM[i][j]);
		}
		printf("\n");
	}
	return;
}

void maxmins()
{
	//calculating rowmins
	int i, j, cur;
	for(i=0; i<ROWS; i++)
	{
		cur=POM[i][0];
		for(j=0; j<COLS; j++)
		{
			if(POM[i][j]<cur)
			{
				cur = POM[i][j];
			}
		}
		POM[i][COLS] = cur;
	}
	
	
	//calculating colmins
	for (i=0; i<COLS; i++)
	{
		cur = POM[0][i];
		for(j=0; j<ROWS; j++)
		{
			if(POM[j][i] > cur)
			{
				cur = POM[j][i];
			}		
		}
		POM [ROWS][i] = cur;
	}
	return;
}

void saddlePoint()
{
	//parsing through rowmins and finding index(max(rowmin))
	int i, row_index=0, max_rowmin=POM[0][COLS];
	for(i=0; i<ROWS; i++)
	{
		if(POM[i][COLS] > max_rowmin)
		{
			row_index = i;
			max_rowmin = POM[i][COLS];
		}
		
	}
	printf("\n\nmax_rowmin: %d at index %d", max_rowmin, row_index);
	//parsing through colmaxs and finding index(min(colmax))
	int j, col_index=0, min_colmax= POM[ROWS][0];
	for(j=0; j<COLS; j++)
	{
		if(POM[ROWS][j] < min_colmax)
		{
			col_index = j;
			min_colmax = POM[ROWS][j];
		}
	}
	printf("\n\nmin_colmax: %d at index %d", min_colmax, col_index);
	//output saddlepoint
	printf("\n\nThe saddlepoint of the given payoff matrix is: (%d, %d)", row_index+1, col_index+1);
	return;
}


int xyCal()
{
	float a11, a12, a21, a22, x1, x2, y1, y2, v;
	a11 = POM[0][0];
	a12 = POM[0][1];
	a21 = POM[1][0];
	a22 = POM[1][1];
	x1 = (a22 - a21) / (a11 + a22 - (a12 + a21));
	x2 = (a11 - a12) / (a11 + a22 - (a12 + a21));
	y1 = (a22 - a12) / (a11 + a22 - (a12 + a21));
	y2 = (a11 - a21) / (a11 + a22 - (a12 + a21));
	v = ((a11 * a22) - (a12 * a21)) / (a11 + a22 - (a12 + a21));
	printf("\nx1: %f", x1);
	printf("\nx2: %f", x2);
	printf("\ny1: %f", y1);
	printf("\ny2: %f", y2);
	printf("\nv: %f", v);
	return 0;
}

//MAIN

int main()
{
	createMatrix();
	maxmins();
	showMatrix();
//	saddlePoint(); 
	xyCal();
	return 0;
}