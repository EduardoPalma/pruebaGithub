#include <stdio.h>
#include <stdlib.h>
#define MAX_DIGITOS 10000
#define MAX 999999999

int factorial(int);
int factorial_recursivo(int);
void factorial_n2(int,int[],int*);
void guardad_digitos(int,int*,int[]);
void imprimir(int[],int);
void rellenar(int[]);
void factoriales(int);

int main(){
	int num = 12;
	int resultado[MAX_DIGITOS];
	int tam_resultado = 0;
	printf("el factorial de %d es : %d",num,factorial(num));
	printf("\nel factorial de %d recursivo es : %d\n",num,factorial_recursivo(num));
	rellenar(resultado);
	factorial_n2(num,resultado,&tam_resultado);
	printf("(ACTIVIDAD 2)el factorial de %d en el vector es : \n",num);
	imprimir(resultado,tam_resultado);
	printf("factoriales de n terminos \n");
	factoriales(num);
}
                                    
int factorial(int num){
	int resultado = 1;
    for(int i=2;i<=num;i++){
      if((i <= num) && (resultado > (MAX/i))){
        return 0;
      }
      resultado = resultado*i;
    }
    return resultado;
}

int factorial_recursivo(int num){
	if(num <= 12){
		if(num == 0)return 1;
		else return (factorial_recursivo(num-1)*num);
	}return 0;
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

void factoriales(int num){
  int i;
  int valor = 0;
  for(i=1;i<=num;i++){
    valor = factorial(i);
    printf(" factorial de %d es : %d\n",i,valor);
  }
}
