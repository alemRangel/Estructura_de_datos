#include <stdlib.h>
#include <stdio.h>

void darDimension(int *elem);
void crearArreglo(int **A,int elem);
void solicitarDatos(int *A,int elem);
void mostrarDatos(int *A,int elem);
void promedio(int *A,int *P,int elem);
void liberar(int *A);

int main(){
	int* A;
        int elem,P;
	darDimension(&elem);
	crearArreglo(&A,elem);
	solicitarDatos(A,elem);
	mostrarDatos(A,elem);
	promedio(A,&P,elem);
	mostrarDatos(&P,0);
	liberar(A);
 	return 0;
}

void darDimension(int *elem){
	printf("Introduzca la dimension del arreglo \n");
	scanf("%d",elem);
}

void crearArreglo(int **A,int elem){
	*A = (int *)malloc(sizeof(int)*elem);
	if(*A == NULL){
		printf("No se pudo reservar \n");
		exit(0);
	}
}

void solicitarDatos(int *A,int elem){
	for(int i=0;i<elem;++i){
		printf("Introduzca el dato %d \n",(i+1));
		scanf("%d", &A[i]);
	}
}

void promedio(int *A, int *P, int elem)
{
	*P = 0;
	for(int i=0; i<elem; ++i){
	*P = *P + A[i];
}
  *P = *P / elem;
}
void mostrarDatos(int *A,int elem){
	if(elem>1)
{
	printf("Los elementos son:");
	for(int i=0;i<elem;++i){
		printf("Elemento %d : %d \n",(i+1),A[i]);
	}
}
	else
	printf("El promedio es:%d \n",*A);	
}

void liberar(int *A){
	free(A);
}
