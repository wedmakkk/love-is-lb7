// dfghj.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>




void generate_matrix(int n, float p, int** adjacency_matrix) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjacency_matrix[i][j] = 0;
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((float)rand() / RAND_MAX < p) {
                adjacency_matrix[i][j] = 1;
                adjacency_matrix[j][i] = 1;
            }
        }
    }
 
}

void print_matrix(int n, int** adjacency_matrix)
{
    printf("Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}


void DFS(int s,int** G,int* vis,int size)

{
	vis[s] = 1;
	printf("%d",s);
	for(int i=0;i<size;i++)
	{
		if(G[s][i]==1 && vis[i] == 0)
		{
			DFS(i,G,vis,size);
		}
	}
	printf("\n");
}
void SFD(int s,int** G,int* vis,int size)
{
	for(int i = 0;i<size;i++)
	{
		if(vis[i]==0)
		{
			DFS(i,G,vis,size);
		}
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	  int n;
    float p;


    srand(time(NULL));


    printf("Input count of peaks  : ");
    scanf("%d", &n);
    
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0;i < n;i++)
    {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }
    printf("Enter the probability of having an edge (0.0 to 1.0):");
    scanf("%f", &p);
    if (p < 0.0 || p > 1.0) {
        printf("The probability should be in the range from 0.0 to 1.0.\n");

        return 1;
    }
	int* vis = (int *)malloc(n*sizeof(int*));
    for(int i =0;i<n;i++)
	{
		vis[i] = 0;
	}
    generate_matrix(n, p, matrix);
	print_matrix(n,matrix);

	int s = 0;
	printf("input start peak:");
	scanf_s("%i",&s);
	DFS(s,matrix,vis,n);
	SFD(s,matrix,vis,n);
	getchar();
	getchar();
	getchar();
	return 0;
}