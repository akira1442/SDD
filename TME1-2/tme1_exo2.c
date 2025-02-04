#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int* alloue_tableau(int n){

	int *t = (int*) malloc(n*sizeof(int));
	return t;
}

void alloue_tableau2 (int **t, int n){

	*t = (int*) (malloc(n*sizeof(int)));
}

void desalloue_tableau(int *t){
	
	free(t);
}

void remplir_tableau(int *t, int n, int V){
	
	for (int i = 0; i < n; i++){
		t[i] = (int)(rand() % V);
	}
}

void afficher_tableau(int *t, int n){

	printf("[ ");
	for (int i = 0; i < n; i++){
		printf("%d ", t[i]);
	}
	printf("]\n");
}

int somme_carre(int *tab, int n){
	
	int res = 0, tmp = 0;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			tmp = tab[i] - tab[j];
			res += tmp * tmp;
		}
	}

	return res;
}

int somme_carre_opt(int *tab, int n){
	
	int som_i = 0, som_j = 0;
	
	for (int i = 0; i < n; i++){
		som_i += tab[i]*tab[i];
		som_j += tab[i];
	}
	
	return 2 * n * som_i - 2 * som_j*som_j;
}

void main(){

	srand(time(NULL));

	int *t = NULL;
	FILE* f = fopen("comparaison_temp.txt", "w");
	
	alloue_tableau2(&t, 5);
	remplir_tableau(t, 5,10);
	afficher_tableau(t, 5);
	desalloue_tableau(t);
	
	int tab[4] = {1,2,3,4};
	
	clock_t temp_initial;
	clock_t temps_final;
	double temps_cpu;

	//fprintf(f, "Algo1 Algo2\n");

	for (int i = 1; i < 5000; i++){

		alloue_tableau2(&t, i);
		remplir_tableau(t, i, 10);

		temp_initial = clock();
		somme_carre(tab, i);
		temps_final = clock();

		temps_cpu = ((double)(temps_final - temp_initial)) / CLOCKS_PER_SEC;

		fprintf(f, "%d %f ", i, temps_cpu);

		temp_initial = clock();
		somme_carre_opt(tab, i);
		temps_final = clock();

		temps_cpu = ((double)(temps_final - temp_initial)) / CLOCKS_PER_SEC;

		fprintf(f, "%f \n", temps_cpu);
		desalloue_tableau(t);
	}
	fclose(f);
	printf("FIN_PROGRAMME\n");
}

