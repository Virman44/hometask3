#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


int main(void) {
	int** a;
	int** b;
	int n, n1, n2;
	scanf("%d", &n);

	a = (int**)malloc(n * sizeof(int*));

	for (int i = 0; i < n; i++) {
		a[i] = (int*)malloc(n * sizeof(int));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	scanf("%d", &n1);

    b = (int**)malloc(n1 * sizeof(int*));

    for (int i = 0; i < n1; i++) {
		b[i] = (int*)malloc(n1 * sizeof(int));
	}

	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n1; j++) {
			scanf("%d", &b[i][j]);
		}
	}

	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n1; j++) {
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
	printf("\n");


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