#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** alloue_matrice(int** mat, int n){
	

	mat = (int**) malloc(sizeof(int)*n*n);
	for (int i = 0; i < n; i++){
		mat[i] = (int*) malloc(sizeof(int)*n);
	}

	return mat;
}

void desalloue_matrice(int** mat, int n){
	
	for (int i = 0; i < n; i++){
		free(mat[i]);
	}
	free(mat);
}
 
void remplir_matrice(int** mat, int n, int V){

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			mat[i][j] = (int)(rand() % V); 
		}
	}
}

void afficher_matrice(int** mat, int n){
	
	printf("[");
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			printf("%d ", mat[i][j]); 
		}
	}
	printf("]\n");
}



void main(){

	int** mat = NULL;
	int n = 5;

	mat = alloue_matrice(mat, n);
	remplir_matrice(mat, n, 10);
	afficher_matrice(mat, n);
	desalloue_matrice(mat, n);
}