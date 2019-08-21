#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void sizeArray(int *);
double* inicializarArray(int);
void conversionGradRad(double *,int);
void insertarAngulo(double*,int);
void calcularSerie(double*,double*,int);
int fact(int n);
void imprimir(double*,int);

int main(){
	int N;
	double *angulos;
	double *serie;
	sizeArray(&N);
	angulos = inicializarArray(N);
	serie = inicializarArray(N);
	insertarAngulo(angulos,N);
	conversionGradRad(angulos,N);
	calcularSerie(serie,angulos,N);
	printf("El valor en radianes es: \n");
	imprimir(angulos,N);
	printf("El valor de la serie es: \n");
	imprimir(serie,N);
	return 0;
}

void calcularSerie(double *serie,double* angulo,int N){
	for(int i=0; i<N; ++i){
		serie[i]= pow(-1,i+1-1) * (pow(angulo[i]*(i+1),2*(i+1)-1))/fact((2*(i+1)-1));	
	}
}

void imprimir(double*array,int N){
 for(int i=0; i<N; ++i){
	printf("El valor del arreglo en %d es:%f \n",(i+1),array[i]);
	}
}
int fact(int n){
int fact = 1;
for(int i=0; i<n; ++i){
	fact = fact*(i+1);
}
return fact;
}

void conversionGradRad(double* angulo,int N){
	for(int i=0; i<N; ++i)
	angulo[i] = (angulo[i]*2*M_PI)/360;	
}

void insertarAngulo(double* angulo,int N){
	for(int i=0; i<N; ++i){	
	printf("Escriba el ángulo que quiere para la posición %d (en grados) \n",i+1);
	scanf("%lf",&angulo[i]);
	}
}

void sizeArray(int *N){
	printf("Teclee el tamaño de la serie \n");
	scanf("%d",N);
}

double* inicializarArray(int N){
	double* array;
	array = (double*) (malloc(sizeof(double)*N));
	if(array == NULL)
	{
		printf("No hay espacio");
		exit(0);
	}
	return array;
}
