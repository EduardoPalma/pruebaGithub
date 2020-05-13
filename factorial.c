#include <stdio.h>
#include <stdlib.h>
#define MAX_DIGITOS 10000

int factorial(int);
int factorial_recursivo(int);
void factorial_n2(int,int[],int*);
void guardad_digitos(int,int*,int[]);
void imprimir(int[],int);
void rellenar(int[]);

int main(){
	int num = 15;
	int resultado[MAX_DIGITOS];
	int tam_resultado = 0;
	printf("el factorial de %d es : %d",num,factorial(num));
	printf("\nel factorial de %d recursivo es : %d\n",num,factorial_recursivo(num));
	rellenar(resultado);
	factorial_n2(num,resultado,&tam_resultado);
	printf("el factorial de %d en el vector es : ",num);
	imprimir(resultado,tam_resultado);
}
                                    
int factorial(int num){
	int valor = num;
	int factor = 1;
	while(valor > 0){
		factor = factor * valor;
		valor= valor-1;
	}
	
	return factor;
}

int factorial_recursivo(int num){
	if(num == 0){
		return 1;
	}else{
		return (factorial_recursivo(num-1)*num);
	}
}

void rellenar(int resultado[MAX_DIGITOS]){
	int i;
	for(i=0;i<MAX_DIGITOS;i++){
		resultado[i] = 0;
	}
}

void imprimir(int resultado[MAX_DIGITOS],int tam_resultado){
	int i;
	for(i=tam_resultado-1;i>=0;i--){
		printf("%d",resultado[i]);
	}
	printf("\n");
}

void guardad_digitos(int num,int *tam_resultado,int resultado[MAX_DIGITOS]){
	int i;
	int max = *tam_resultado;
	int multi = 0;
	int resto = 0;
	for(i=0;i<max;i++){
			multi = (resultado[i]*num)+resto;
			resultado[i] = multi%10;
			resto = multi/10;
	}
	if(resto != 0){
		resultado[i] = resto;
		*tam_resultado = *tam_resultado +1; 
	}
}

void factorial_n2(int n,int resultado[MAX_DIGITOS],int *tam_resultado){
	resultado[0] = n;
	int valor = n-1;
	*tam_resultado = 1; 
	while(valor>1){
		guardad_digitos(valor,tam_resultado,resultado);
		valor--;
	}
}

