#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>


int main(void) {
	int** a;
	int** b;
	int n, n1, n2;
	srand(time(NULL));
	n = 3 + rand() % 20;
	a = (int**)malloc(n * sizeof(int*));

	for (int i = 0; i < n; i++) {
		a[i] = (int*)malloc(n * sizeof(int));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = rand() % 2;
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}

	printf("\n");

	n1 = 3 + rand() % 20;
	b = (int**)malloc(n1 * sizeof(int*));

	for (int i = 0; i < n1; i++) {
		b[i] = (int*)malloc(n1 * sizeof(int));
	}

	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n1; j++) {
			b[i][j] = rand() % 2;
		}
	}

	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n1; j++) {
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}

	if (n >= n1) {
		n2 = n1;
	}
	else {
		n2 = n;
	}


	FILE* graphs;
	graphs = fopen("graphhometask.dot", "w");
	fprintf(graphs, "graph graphhometask {\n");

	for (int i = 0; i < n2; i++) {
		for (int j = 0; j < n2; j++) {
			if (a[i][j] == b[i][j]) {
				if (a[j][i] != b[j][i]) {
					fprintf(graphs, "\"%d\"->\"%d\";\n", i + 1, j + 1);
				}
				if (a[j][i] == b[j][i]) {
					fprintf(graphs, "\"%d\" -- \"%d\";\n", i + 1, j + 1);
					a[j][i] = -1;
				}
			}
		}
	}
	fprintf(graphs, "}");
	fclose(graphs);
}
