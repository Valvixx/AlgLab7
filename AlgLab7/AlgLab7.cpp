#define _CRT_SECURE_NO_WARNINGS
#include <malloc.h>
#include <random>
#include <time.h>

int** createG(int size) {
	int** G;
	G = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++) {
		G[i] = (int*)malloc(size * sizeof(int));
	}
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			G[i][j] = rand() % 2;
			if (i == j) G[i][j] = 0;
			G[j][i] = G[i][j];
		}
	}
	return G;
}

void printG(int** G, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%d ", G[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void DFS(int s, int **G, int size, int *vis) {
	vis[s] = 1;
	printf("%d", s);
	for (int i = 0; i < size; i++)
	{
		if (G[s][i] == 1 && vis[i] == 0)
		{
			DFS(i, G, size, vis);
		}
	}
}


int main(int argc, char* argv[])
{
	int** G = NULL;
	int size = 5;
	int* vis = NULL;
	int s = 1;


	printf("Enter number of verts:");
	scanf("%d", &size);

	G = createG(size);
	printG(G, size);

	printf("Enter start vert:");
	

	vis = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++)
	{
		vis[i] = 0;
	}
	scanf("%d", &s);
	printf("Graph check:\n");

	DFS(s, G, size, vis);
}