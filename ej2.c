#include <stdio.h>
#include <stdlib.h>

//Prototipos 
//Ejercicio de clase: Realizar la resta de 2 matrices y guardarla en una tercera ,atriz

void darDimension(int *,int *);
int** crearMatriz(int,int);
void solicitarDatos(int**,int,int,char);
void mostrarDatos(int**,int,int,char);
void restaMatrices(int**,int**,int**,int,int);
void liberar(int**,int);

int main(){
 int **A,**B,**C,fil,col;
	darDimension(&fil,&col);
	A = crearMatriz(fil,col);
	B = crearMatriz(fil,col);
	C = crearMatriz(fil,col);
	solicitarDatos(A,fil,col,'A');
	solicitarDatos(B,fil,col,'B');
	mostrarDatos(A,fil,col,'A');
	mostrarDatos(B,fil,col,'B');
	restaMatrices(A,B,C,fil,col);
	mostrarDatos(C,fil,col,'C');
	liberar(A,fil);
	liberar(B,fil);
	liberar(C,fil);
 return 0;
}

void darDimension(int *fil,int *col){
	printf("Introduzca la dimension m*n \n");
	printf("Introduzca m \n");
	scanf("%d",fil);
	printf("Introduzca n \n");
	scanf("%d",col);
}
int** crearMatriz(int fil,int col){
	int **mtz = (int**)(malloc(sizeof(int*)*fil));
	if(mtz == NULL){
		printf("No hay espacio en la memoria");
		exit(0);
	}
	for(int i=0; i<fil; ++i){
		mtz[i] = (int*)malloc(sizeof(int)*col);
		if(mtz[i] == NULL)
			{
			printf("No hay espacio en la memoria");
		        exit(0);			
			}
	}
 return mtz;
}
void solicitarDatos(int**mtz,int fil,int col,char nom){
	printf("Solicitar Datos \n");
	for(int i=0; i<fil;++i){
		for(int j=0; j<col;++j){
		printf("Matriz %c [%d][%d] \n",nom,i+1,j+1);
		scanf("%d",&mtz[i][j]);
	}	
	}
}
void mostrarDatos(int**mtz,int fil,int col,char nom){
	printf("Mostrar Datos \n");
	for(int i=0; i<fil;++i){
		for(int j=0; j<col;++j){
		printf("Matriz %c [%d][%d] = %d \n",nom,i+1,j+1,mtz[i][j]);
	}	
	}
}
void restaMatrices(int **A,int **B,int **C,int fil,int col){
	printf("LLegué 1");
	for(int i=0; i<fil; ++i){
		for(int j=0; j<col; ++j){
		C[i][j] = A[i][j]-B[i][j];
	}	
	}	
 	printf("LLegué 2");
}
void liberar(int**mtz,int fil){
	for(int i=0; i<fil; ++i){
		free(mtz[i]);	
	}
	free(mtz);
}
